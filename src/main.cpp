#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../include/json.h"
#include "../include/longStrings.h"
using namespace std;

int main(int argc, char *argv[])
{
    ifstream setupFile;
    ofstream headerFile("defines.h");

    Json::Reader reader;
    Json::Value boardsConfigs;

    if (!reader.parse(boardsJson, boardsConfigs))
    {
        cout << "Error parsing boardsConfig.json\n";
        return 1;
    }

    headerFile << "#ifndef DEFINES_H\n#define DEFINES_H\n\n";

    if (argc < 2)
    {
        cout << "txt mode\n";

        string pinName, pinNumber;
        setupFile.open("setup.txt");
        while (getline(setupFile, pinName, ' '))
        {
            getline(setupFile, pinNumber, '\n');
            headerFile << "#define " << pinName << "_wPort " << boardsConfigs[pinNumber]["wPort"].asString() << endl;
            headerFile << "#define " << pinName << "_rPort " << boardsConfigs[pinNumber]["rPort"].asString() << endl;
            headerFile << "#define " << pinName << "_bit " << boardsConfigs[pinNumber]["bit"].asString() << "\n\n";
        }
    }

    else
    {
        string arg1(argv[1]);
        if (arg1 == "-json")
        {
            cout << "json mode\n";

            Json::Value setupJson;
            (argc > 2) ? setupFile.open(argv[2]) : setupFile.open("setup.json");
            if (!reader.parse(setupFile, setupJson))
            {
                cout << "Error parsing setup.json\n";
                return 1;
            }

            for (auto const &pinNumber : setupJson["Connections"].getMemberNames())
            {
                for (auto const &_pinNumber : boardsConfigs.getMemberNames())
                {
                    if (pinNumber == _pinNumber)
                    {
                        string pinName = setupJson["Connections"][pinNumber]["Name"].asString();
                        replace(pinName.begin(), pinName.end(), ' ', '_');

                        headerFile << "#define " << pinName << "_wPort " << boardsConfigs[pinNumber]["wPort"].asString() << endl;
                        headerFile << "#define " << pinName << "_rPort " << boardsConfigs[pinNumber]["rPort"].asString() << endl;
                        headerFile << "#define " << pinName << "_bit " << boardsConfigs[pinNumber]["bit"].asString() << "\n\n";
                    }
                }
            }
        }
    }
    headerFile << macros;

    setupFile.close();
    headerFile.close();

    return 0;
}
