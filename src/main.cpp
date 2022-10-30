#include "../include/main.h"

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
            startMap();
            cout << "json mode\n";

            Json::Value setupJson;
            (argc > 2) ? setupFile.open(argv[2]) : setupFile.open("setup.json");
            if (!reader.parse(setupFile, setupJson))
            {
                cout << "Error parsing setup.json\n";
                return 1;
            }

            string pinName, boardName = setupJson["Board"].asString();

            for (auto const &pinNumber : setupJson["Connections"].getMemberNames())
            {
                for (auto const &_pinNumber : boardsConfigs[boardName].getMemberNames())
                {
                    if (pinNumber == _pinNumber)
                    {
                        pinName = setupJson["Connections"][pinNumber]["Name"].asString();

                        replace(pinName.begin(), pinName.end(), ' ', '_');
                        replace(pinName.begin(), pinName.end(), '/', '_');
                        char pinNameFormated[pinName.length()];
                        removeAccents(pinName, pinNameFormated);

                        headerFile << "#define " << pinNameFormated << "_wPort " << boardsConfigs[boardName][pinNumber]["wPort"].asString() << endl;
                        headerFile << "#define " << pinNameFormated << "_rPort " << boardsConfigs[boardName][pinNumber]["rPort"].asString() << endl;
                        headerFile << "#define " << pinNameFormated << "_bit " << boardsConfigs[boardName][pinNumber]["bit"].asString() << "\n\n";
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

void removeAccents(string str, char *out)
{
    uint8_t accents = 0;

    if (str.empty())
        return;

    for (int i = 0; i <= str.length(); i++)
    {
        string strInterval = str.substr(i, 2);

        if (specialCharacters.find(strInterval) != specialCharacters.end())
        {
            out[i - accents] = specialCharacters.find(strInterval)->second;
            accents++;
            i++;
        }
        else
            out[i - accents] = str[i];
        cout << specialCharacters.find(strInterval)->second << "\nout: " << out << endl;
    }
}

void startMap()
{
    specialCharacters.insert(pair<string, char>("á", 'a'));
    specialCharacters.insert(pair<string, char>("à", 'a'));
    specialCharacters.insert(pair<string, char>("ã", 'a'));
    specialCharacters.insert(pair<string, char>("â", 'a'));
    specialCharacters.insert(pair<string, char>("é", 'e'));
    specialCharacters.insert(pair<string, char>("è", 'e'));
    specialCharacters.insert(pair<string, char>("ê", 'e'));
    specialCharacters.insert(pair<string, char>("í", 'i'));
    specialCharacters.insert(pair<string, char>("ì", 'i'));
    specialCharacters.insert(pair<string, char>("î", 'i'));
    specialCharacters.insert(pair<string, char>("ó", 'o'));
    specialCharacters.insert(pair<string, char>("ò", 'o'));
    specialCharacters.insert(pair<string, char>("õ", 'o'));
    specialCharacters.insert(pair<string, char>("ô", 'o'));
    specialCharacters.insert(pair<string, char>("ú", 'u'));
    specialCharacters.insert(pair<string, char>("ù", 'u'));
    specialCharacters.insert(pair<string, char>("û", 'u'));
    specialCharacters.insert(pair<string, char>("ç", 'c'));
    specialCharacters.insert(pair<string, char>("ñ", 'n'));
    specialCharacters.insert(pair<string, char>("Á", 'A'));
    specialCharacters.insert(pair<string, char>("À", 'A'));
    specialCharacters.insert(pair<string, char>("Ã", 'A'));
    specialCharacters.insert(pair<string, char>("Â", 'A'));
    specialCharacters.insert(pair<string, char>("É", 'E'));
    specialCharacters.insert(pair<string, char>("È", 'E'));
    specialCharacters.insert(pair<string, char>("Ê", 'E'));
    specialCharacters.insert(pair<string, char>("Í", 'I'));
    specialCharacters.insert(pair<string, char>("Ì", 'I'));
    specialCharacters.insert(pair<string, char>("Î", 'I'));
    specialCharacters.insert(pair<string, char>("Ó", 'O'));
    specialCharacters.insert(pair<string, char>("Ò", 'O'));
    specialCharacters.insert(pair<string, char>("Õ", 'O'));
    specialCharacters.insert(pair<string, char>("Ô", 'O'));
    specialCharacters.insert(pair<string, char>("Ú", 'U'));
    specialCharacters.insert(pair<string, char>("Ù", 'U'));
    specialCharacters.insert(pair<string, char>("Û", 'U'));
    specialCharacters.insert(pair<string, char>("Ç", 'C'));
    specialCharacters.insert(pair<string, char>("Ñ", 'N'));
}