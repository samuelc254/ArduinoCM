#include "../include/main.h"

int main(int argc, char *argv[])
{
    uint8_t externConfig = 0,
            variantSetup = 0,
            variantHeader = 0;

    // cout << argc << " argv[0] = " << argv[0] << " argv[1] = " << argv[1] << " argv[2] = " << argv[2] << endl;

    startMap();
    ifstream setupFile;
    ofstream headerFile;
    Json::Reader reader;
    Json::Value configJson;
    Json::Value setupJson;

    for (int i = 0; i < argc; i++)
    {
        string arg(argv[i]);

        if (arg == "-c")
        {
            externConfig = 1;
            ifstream configFile(argv[i + 1]);
            if (!reader.parse(configFile, configJson))
            {
                cout << "Error parsing config file" << endl;
                return 1;
            }
            configFile.close();
            cout << "using extern config file" << endl;
        }
        else if (i == (argc - 1) && externConfig == 0)
        {
            reader.parse(configString, configJson);
            cout << "using default config file" << endl;
        }

        if (arg == "-i")
        {
            variantSetup = 1;
            setupFile.open(argv[i + 1]);
            if (!reader.parse(setupFile, setupJson))
            {
                cout << "Error parsing " << argv[i + 1] << endl;
                return 1;
            }
            cout << "using alternative setup file" << endl;
        }
        else if (i == (argc - 1) && variantSetup == 0)
        {
            setupFile.open("setup.json");
            if (!reader.parse(setupFile, setupJson))
            {
                cout << "Error parsing setup.json" << endl;
                return 1;
            }
            cout << "using default setup file" << endl;
        }

        if (arg == "-o")
        {
            variantHeader = 1;
            headerFile.open(argv[i + 1]);
            cout << "using alternative header file" << endl;
        }
        else if (i == (argc - 1) && variantHeader == 0)
        {
            headerFile.open("header.h");
            cout << "using default header file" << endl;
        }
    }

    string pinName, boardName = setupJson["Board"].asString();
    headerFile << "#ifndef DEFINES_H\n#define DEFINES_H\n#define cpu_map_for_" << boardName << "\n\n";
    for (auto const &pinNumber : setupJson["Connections"].getMemberNames())
    {
        for (auto const &_pinNumber : configJson[boardName].getMemberNames())
        {
            if (pinNumber == _pinNumber)
            {
                pinName = setupJson["Connections"][pinNumber]["Name"].asString();

                replace(pinName.begin(), pinName.end(), ' ', '_');
                replace(pinName.begin(), pinName.end(), '/', '_');
                char pinNameFormated[pinName.length()];
                removeAccents(pinName, pinNameFormated);

                headerFile << "#define " << pinNameFormated << "_wPort " << configJson[boardName][pinNumber]["wPort"].asString() << endl;
                headerFile << "#define " << pinNameFormated << "_rPort " << configJson[boardName][pinNumber]["rPort"].asString() << endl;
                headerFile << "#define " << pinNameFormated << "_bit " << configJson[boardName][pinNumber]["bit"].asString() << "\n\n";
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