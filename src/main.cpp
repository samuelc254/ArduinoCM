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

        if (strInterval == "á")
        {
            out[i - accents] = 'a';
            accents++;
            i++;
        }
        else if (strInterval == "à")
        {
            out[i - accents] = 'a';
            accents++;
            i++;
        }
        else if (strInterval == "ã")
        {
            out[i - accents] = 'a';
            accents++;
            i++;
        }
        else if (strInterval == "â")
        {
            out[i - accents] = 'a';
            accents++;
            i++;
        }
        else if (strInterval == "é")
        {
            out[i - accents] = 'e';
            accents++;
            i++;
        }
        else if (strInterval == "è")
        {
            out[i - accents] = 'e';
            accents++;
            i++;
        }
        else if (strInterval == "ê")
        {
            out[i - accents] = 'e';
            accents++;
            i++;
        }
        else if (strInterval == "í")
        {
            out[i - accents] = 'i';
            accents++;
            i++;
        }
        else if (strInterval == "ì")
        {
            out[i - accents] = 'i';
            accents++;
            i++;
        }
        else if (strInterval == "î")
        {
            out[i - accents] = 'i';
            accents++;
            i++;
        }
        else if (strInterval == "ó")
        {
            out[i - accents] = 'o';
            accents++;
            i++;
        }
        else if (strInterval == "ò")
        {
            out[i - accents] = 'o';
            accents++;
            i++;
        }
        else if (strInterval == "õ")
        {
            out[i - accents] = 'o';
            accents++;
            i++;
        }
        else if (strInterval == "ô")
        {
            out[i - accents] = 'o';
            accents++;
            i++;
        }
        else if (strInterval == "ú")
        {
            out[i - accents] = 'u';
            accents++;
            i++;
        }
        else if (strInterval == "ù")
        {
            out[i - accents] = 'u';
            accents++;
            i++;
        }
        else if (strInterval == "û")
        {
            out[i - accents] = 'u';
            accents++;
            i++;
        }
        else if (strInterval == "ç")
        {
            out[i - accents] = 'c';
            accents++;
            i++;
        }
        else if (strInterval == "Á")
        {
            out[i - accents] = 'A';
            accents++;
            i++;
        }
        else if (strInterval == "À")
        {
            out[i - accents] = 'A';
            accents++;
            i++;
        }
        else if (strInterval == "Ã")
        {
            out[i - accents] = 'A';
            accents++;
            i++;
        }
        else if (strInterval == "Â")
        {
            out[i - accents] = 'A';
            accents++;
            i++;
        }
        else if (strInterval == "É")
        {
            out[i - accents] = 'E';
            accents++;
            i++;
        }
        else if (strInterval == "È")
        {
            out[i - accents] = 'E';
            accents++;
            i++;
        }
        else if (strInterval == "Ê")
        {
            out[i - accents] = 'E';
            accents++;
            i++;
        }
        else if (strInterval == "Í")
        {
            out[i - accents] = 'I';
            accents++;
            i++;
        }
        else if (strInterval == "Ì")
        {
            out[i - accents] = 'I';
            accents++;
            i++;
        }
        else if (strInterval == "Î")
        {
            out[i - accents] = 'I';
            accents++;
            i++;
        }
        else if (strInterval == "Ó")
        {
            out[i - accents] = 'O';
            accents++;
            i++;
        }
        else if (strInterval == "Ò")
        {
            out[i - accents] = 'O';
            accents++;
            i++;
        }
        else if (strInterval == "Õ")
        {
            out[i - accents] = 'O';
            accents++;
            i++;
        }
        else if (strInterval == "Ô")
        {
            out[i - accents] = 'O';
            accents++;
            i++;
        }
        else if (strInterval == "Ú")
        {
            out[i - accents] = 'U';
            accents++;
            i++;
        }
        else if (strInterval == "Ù")
        {
            out[i - accents] = 'U';
            accents++;
            i++;
        }
        else if (strInterval == "Û")
        {
            out[i - accents] = 'U';
            accents++;
            i++;
        }
        else if (strInterval == "Ç")
        {
            out[i - accents] = 'C';
            accents++;
            i++;
        }
        else
        {
            out[i - accents] = str[i];
        }
    }
}