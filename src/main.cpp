#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

string pinName, pinNumber;

int main()
{

    map<string, string> writePort;
    writePort["0"] = "PORTD";
    writePort["1"] = "PORTD";
    writePort["2"] = "PORTD";
    writePort["3"] = "PORTD";
    writePort["4"] = "PORTD";
    writePort["5"] = "PORTD";
    writePort["6"] = "PORTD";
    writePort["7"] = "PORTD";
    writePort["8"] = "PORTB";
    writePort["9"] = "PORTB";
    writePort["10"] = "PORTB";
    writePort["11"] = "PORTB";
    writePort["12"] = "PORTB";
    writePort["13"] = "PORTB";
    writePort["A0"] = "PORTC";
    writePort["A1"] = "PORTC";
    writePort["A2"] = "PORTC";
    writePort["A3"] = "PORTC";
    writePort["A4"] = "PORTC";
    writePort["A5"] = "PORTC";
    writePort["PD0"] = "PORTD";
    writePort["PD1"] = "PORTD";
    writePort["PD2"] = "PORTD";
    writePort["PD3"] = "PORTD";
    writePort["PD4"] = "PORTD";
    writePort["PD5"] = "PORTD";
    writePort["PD6"] = "PORTD";
    writePort["PD7"] = "PORTD";
    writePort["PB0"] = "PORTB";
    writePort["PB1"] = "PORTB";
    writePort["PB2"] = "PORTB";
    writePort["PB3"] = "PORTB";
    writePort["PB4"] = "PORTB";
    writePort["PB5"] = "PORTB";
    writePort["PC0"] = "PORTC";
    writePort["PC1"] = "PORTC";
    writePort["PC2"] = "PORTC";
    writePort["PC3"] = "PORTC";
    writePort["PC4"] = "PORTC";
    writePort["PC5"] = "PORTC";

    map<string, string> readPort;
    readPort["0"] = "PIND";
    readPort["1"] = "PIND";
    readPort["2"] = "PIND";
    readPort["3"] = "PIND";
    readPort["4"] = "PIND";
    readPort["5"] = "PIND";
    readPort["6"] = "PIND";
    readPort["7"] = "PIND";
    readPort["8"] = "PINB";
    readPort["9"] = "PINB";
    readPort["10"] = "PINB";
    readPort["11"] = "PINB";
    readPort["12"] = "PINB";
    readPort["13"] = "PINB";
    readPort["A0"] = "PINC";
    readPort["A1"] = "PINC";
    readPort["A2"] = "PINC";
    readPort["A3"] = "PINC";
    readPort["A4"] = "PINC";
    readPort["A5"] = "PINC";
    readPort["PD0"] = "PIND";
    readPort["PD1"] = "PIND";
    readPort["PD2"] = "PIND";
    readPort["PD3"] = "PIND";
    readPort["PD4"] = "PIND";
    readPort["PD5"] = "PIND";
    readPort["PD6"] = "PIND";
    readPort["PD7"] = "PIND";
    readPort["PB0"] = "PINB";
    readPort["PB1"] = "PINB";
    readPort["PB2"] = "PINB";
    readPort["PB3"] = "PINB";
    readPort["PB4"] = "PINB";
    readPort["PB5"] = "PINB";
    readPort["PC0"] = "PINC";
    readPort["PC1"] = "PINC";
    readPort["PC2"] = "PINC";
    readPort["PC3"] = "PINC";
    readPort["PC4"] = "PINC";
    readPort["PC5"] = "PINC";

    map<string, string> portBit;
    portBit["0"] = "0";
    portBit["1"] = "1";
    portBit["2"] = "2";
    portBit["3"] = "3";
    portBit["4"] = "4";
    portBit["5"] = "5";
    portBit["6"] = "6";
    portBit["7"] = "7";
    portBit["8"] = "0";
    portBit["9"] = "1";
    portBit["10"] = "2";
    portBit["11"] = "3";
    portBit["12"] = "4";
    portBit["13"] = "5";
    portBit["A0"] = "0";
    portBit["A1"] = "1";
    portBit["A2"] = "2";
    portBit["A3"] = "3";
    portBit["A4"] = "4";
    portBit["A5"] = "5";
    portBit["PD0"] = "0";
    portBit["PD1"] = "1";
    portBit["PD2"] = "2";
    portBit["PD3"] = "3";
    portBit["PD4"] = "4";
    portBit["PD5"] = "5";
    portBit["PD6"] = "6";
    portBit["PD7"] = "7";
    portBit["PB0"] = "0";
    portBit["PB1"] = "1";
    portBit["PB2"] = "2";
    portBit["PB3"] = "3";
    portBit["PB4"] = "4";
    portBit["PB5"] = "5";
    portBit["PC0"] = "0";
    portBit["PC1"] = "1";
    portBit["PC2"] = "2";
    portBit["PC3"] = "3";
    portBit["PC4"] = "4";
    portBit["PC5"] = "5";

    ofstream outputFile("defines.h");
    ifstream setupFile("setup.txt");

    outputFile << "#ifndef DEFINES_H\n#define DEFINES_H\n\n";

    for (string buffer; getline(setupFile, buffer);)
    {
        cout << buffer << ":\n";
        stringstream readLine(buffer);

        getline(readLine, pinName, ' ');

        getline(readLine, pinNumber, ' ');

        for (auto element : writePort)
        {
            if (pinNumber == element.first)
            {
                outputFile << "#define " << pinName << "_wPort " << element.second << endl;
                cout << "#define " << pinName << "_wPort " << element.second << endl;
            }
        }
        for (auto element : readPort)
        {
            if (pinNumber == element.first)
            {
                outputFile << "#define " << pinName << "_rPort " << element.second << endl;
                cout << "#define " << pinName << "_rPort " << element.second << endl;
            }
        }
        for (auto element : portBit)
        {
            if (pinNumber == element.first)
            {
                outputFile << "#define " << pinName << "_bit " << element.second << "\n\n";
                cout << "#define " << pinName << "_bit " << element.second << "\n\n";
            }
        }
    }

    outputFile << "#define SetBit(RES, BIT)(RES |= (1 << BIT)) // Por BIT em nível alto\n#define ClrBit(RES, BIT)(RES &= ~ (1 << BIT)) // Por BIT em nível baixo\n#define TstBit(RES, BIT)(RES &  (1 << BIT)) // testar BIT, retorna 0 ou 1\n#define CplBit(RES, BIT)(RES ^= (1 << BIT)) // Inverter estado do BIT\n#define WriteBit(RES, BIT, VAL) (VAL)?SetBit(RES, BIT):ClrBit(RES, BIT) // Escrever VAL no BIT\n\n#endif";
    setupFile.close();
    outputFile.close();
}
