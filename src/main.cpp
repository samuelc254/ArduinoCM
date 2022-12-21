#include "../include/main.h"

int main(int argc, char *argv[])
{
    externConfig = 0;
    variantSetup = 0;
    variantHeader = 0;
    generateCfile = 0;
    useCSV = 0;

    initCharactersMap();

    // check the given arguments
    for (int i = 0; i < argc; i++)
    {
        string arg(argv[i]);

        if ((arg == "-help") || (arg == "-h") || (arg == "help"))
        {
            cout << helpMsg;
            return 0;
        }

        if (arg == "-c")
        {
            externConfig = 1;
            arg_c = argv[i + 1];
        }
        if (arg == "-i")
        {
            variantSetup = 1;
            arg_i = argv[i + 1];
        }
        if (arg == "-o")
        {
            variantHeader = 1;
            arg_o = argv[i + 1];
        }
        if (arg == "-g")
            generateCfile = 1;
    }

    // setup using given arguments
    if (externConfig)
    {
        ifstream configFile(arg_c);
        cout << "using " << arg_c << " config file" << endl;
        if (!reader.parse(configFile, configJson))
        {
            cout << "Error parsing (" << arg_c << ") using default config file\n";
            reader.parse(configString, configJson);
        }
        configFile.close();
    }
    else
    {
        cout << "using default config file" << endl;
        reader.parse(configString, configJson);
    }

    if (variantSetup)
    {
        setupFile.open(arg_i);
        if (!reader.parse(setupFile, setupJson))
        {
            cout << "Error parsing " << arg_i << endl;
            return 1;
        }
        cout << "using " << arg_i << " setup file\n";
    }
    else
    {
        cout << "using default setup file" << endl;
        setupFile.open("setup.json");
        if (!reader.parse(setupFile, setupJson))
        {
            cout << "Error parsing setup.json looking for .csv file\n";

            setupFile.open("setup.csv");
            getline(setupFile, boardName, ',');
            if (boardName != "board")
            {
                cout << "Error parsing setup.csv\n";
                return 1;
            }
            useCSV = 1;
            cout << "using csv file" << endl;
        }
    }

    if (variantHeader)
    {
        stringstream input_stringstream(arg_o);
        getline(input_stringstream, outFileName, '.');
        headerFile.open(outFileName + (string)(".h"));
    }
    else
    {
        if (useCSV)
        {
            getline(setupFile, boardName);
            outFileName = boardName + (string)("_cpu_map");
        }
        else
        {
            outFileName = setupJson["Board"].asString() + (string)("_cpu_map");
        }
        headerFile.open(outFileName + (string)(".h"));
    }
    cout << "creating cpu map as " << outFileName << ".h\n";

    if (generateCfile && variantHeader)
    {
        codeFile.open(outFileName + (string)(".c"));
        codeFile << R"(#include ")" << outFileName + (string)(".h") << R"(")";
        codeFile << "\n\nvoid initPins(){\n\n";
    }
    else if (generateCfile)
    {
        codeFile.open(outFileName + (string)(".c"));
        codeFile << R"(#include ")" << outFileName + (string)(".h") << R"(")";
        codeFile << "\n\nvoid initPins()\n{\n";
    }

    // start writing files
    headerFile << "#ifndef " << outFileName << "_H\n"
               << "#define " << outFileName << "_H\n\n";

    if (useCSV)
        generateFromCSV();
    else
        generateFromJson();

    headerFile << macros;
    if (generateCfile)
    {
        headerFile << "void initPins();\n\n#endif";
        codeFile << "}";
    }
    else
        headerFile << "#endif";

    setupFile.close();
    headerFile.close();
    codeFile.close();

    return 0;
}

void generateFromCSV()
{
    while (getline(setupFile, pinName, ','))
    {
        getline(setupFile, pinNumber, ',');
        getline(setupFile, pinMode);
        for (auto const &_pinNumber : configJson[boardName].getMemberNames())
        {
            if (pinNumber == _pinNumber)
            {
                replace(pinName.begin(), pinName.end(), ' ', '_');
                replace(pinName.begin(), pinName.end(), '/', '_');
                char pinNameFormated[pinName.length()];
                removeAccents(pinName, pinNameFormated);

                headerFile << "#define " << pinNameFormated << "_ddr " << configJson[boardName][pinNumber]["ddr"].asString() << endl;
                headerFile << "#define " << pinNameFormated << "_wPort " << configJson[boardName][pinNumber]["wPort"].asString() << endl;
                headerFile << "#define " << pinNameFormated << "_rPort " << configJson[boardName][pinNumber]["rPort"].asString() << endl;
                headerFile << "#define " << pinNameFormated << "_bit " << configJson[boardName][pinNumber]["bit"].asString() << "\n\n";

                if (generateCfile)
                {
                    if (pinMode == "output")
                        codeFile << "SetBit(" << pinNameFormated << "_ddr, " << pinNameFormated << "_bit) // output\n\n";
                    if (pinMode == "input")
                        codeFile << "ClrBit(" << pinNameFormated << "_ddr, " << pinNameFormated << "_bit) // input\n\n";
                    if (pinMode == "inputPullup")
                    {
                        codeFile << "ClrBit(" << pinNameFormated << "_ddr, " << pinNameFormated << "_bit) // input\n";
                        codeFile << "SetBit(" << pinNameFormated << "_wPort, " << pinNameFormated << "_bit) // pullup\n\n";
                    }
                }
            }
        }
    }
}

void generateFromJson()
{
    boardName = setupJson["Board"].asString();
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

                headerFile << "#define " << pinNameFormated << "_ddr " << configJson[boardName][pinNumber]["ddr"].asString() << endl;
                headerFile << "#define " << pinNameFormated << "_wPort " << configJson[boardName][pinNumber]["wPort"].asString() << endl;
                headerFile << "#define " << pinNameFormated << "_rPort " << configJson[boardName][pinNumber]["rPort"].asString() << endl;
                headerFile << "#define " << pinNameFormated << "_bit " << configJson[boardName][pinNumber]["bit"].asString() << "\n\n";

                if (generateCfile)
                {
                    if (setupJson["Connections"][pinNumber]["InOut"].asString() == "Output")
                        codeFile << "SetBit(" << pinNameFormated << "_ddr, " << pinNameFormated << "_bit) // output\n\n";
                    if (setupJson["Connections"][pinNumber]["InOut"].asString() == "Input")
                        codeFile << "ClrBit(" << pinNameFormated << "_ddr, " << pinNameFormated << "_bit) // input\n\n";
                    if (setupJson["Connections"][pinNumber]["InOut"].asString() == "InputPullup")
                    {
                        codeFile << "ClrBit(" << pinNameFormated << "_ddr, " << pinNameFormated << "_bit) // input\n";
                        codeFile << "SetBit(" << pinNameFormated << "_wPort, " << pinNameFormated << "_bit) // pullup\n\n";
                    }
                }
            }
        }
    }
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

void initCharactersMap()
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