#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include "../include/json.h"
using namespace std;

ifstream setupFile;
ofstream headerFile;
ofstream codeFile;
Json::Reader reader;
Json::Value configJson;
Json::Value setupJson;

uint8_t externConfig,
    variantSetup,
    variantHeader,
    generateCfile;

string outFileName,
    arg_c,
    arg_i,
    arg_o,
    arg_g;

map<string, char> specialCharacters;

void generateFromJson();

void removeAccents(string str, char *out);

void startMap();

int main(int argc, char *argv[]);

const char *helpMsg = R"(
╔═════════════════════════════════════════════════════╗
║                  ARDUINO CPU MAPPER                 ║
╠═════════════════════════════════════════════════════╣
║-help || -h shows this message                       ║
║-c choose an external configuration file             ║
║-i specify the setup file name                       ║
║-o specify the output file name                      ║
║-g generate input/output configurations in a .c file ║
║                                                     ║
║   for more info: github.com/samuelc254/ArduinoCM    ║
╚═════════════════════════════════════════════════════╝
)";

const char *macros = R"(#define SetBit(RES, BIT)(RES |= (1 << BIT)) // Set BIT in RES to HIGH
#define ClrBit(RES, BIT)(RES &= ~ (1 << BIT)) // Set BIT in RES to LOW
#define TstBit(RES, BIT)(RES &  (1 << BIT)) // Test BIT in RES and return 0 or 1
#define InvBit(RES, BIT)(RES ^= (1 << BIT)) // Invert BIT in RES (0 to 1 and 1 to 0)
#define WriteBit(RES, BIT, VAL) (VAL)?SetBit(RES, BIT):ClrBit(RES, BIT) // Write VAL in BIT in RES (0 or 1)

)";

const char *configString = R"( 
{
    "UNO": {
        "8": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "D8": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "PB0": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "9": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "D9": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "PB1": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "10": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "D10": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "PB2": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "SS": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "11": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "D11": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "PB3": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "MOSI": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "12": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "D12": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "PB4": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "MISO": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "13": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "D13": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "PB5": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "SCK": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "14": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "D14": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "PC0": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "A0": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "15": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "D15": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "PC1": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "A1": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "16": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "D16": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "PC2": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "A2": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "17": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "D17": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "PC3": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "A3": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "18": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "D18": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "PC4": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "A4": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "SDA": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "19": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "D19": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "PC5": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "A5": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "SCL": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "0": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "0"
        },
        "D0": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "0"
        },
        "PD0": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "6"
        },
        "RX": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "0"
        },
        "1": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "1"
        },
        "D1": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "1"
        },
        "PD1": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "7"
        },
        "TX": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "1"
        },
        "2": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "D2": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "PD2": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "INT0": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "3": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "D3": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "PD3": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "INT1": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "4": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "4"
        },
        "D4": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "4"
        },
        "PD4": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "4"
        },
        "5": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "5"
        },
        "D5": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "5"
        },
        "PD5": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "5"
        },
        "6": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "6"
        },
        "D6": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "6"
        },
        "7": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "7"
        },
        "D7": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "7"
        }
    },
    "MEGA": {
        "D22": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "0"
        },
        "22": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "0"
        },
        "PA0": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "0"
        },
        "D23": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "1"
        },
        "23": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "1"
        },
        "PA1": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "1"
        },
        "D24": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "2"
        },
        "24": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "2"
        },
        "PA2": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "2"
        },
        "D25": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "3"
        },
        "25": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "3"
        },
        "PA3": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "3"
        },
        "D26": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "4"
        },
        "26": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "4"
        },
        "PA4": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "4"
        },
        "D27": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "5"
        },
        "27": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "5"
        },
        "PA5": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "5"
        },
        "D28": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "6"
        },
        "28": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "6"
        },
        "PA6": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "6"
        },
        "D29": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "7"
        },
        "29": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "7"
        },
        "PA7": {
            "ddr": "DDRA",
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "7"
        },
        "D53": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "53": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "SS": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "PB0": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "D52": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "52": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "SCK": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "PB1": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "D51": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "51": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "MOSI": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "PB2": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "D50": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "50": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "MISO": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "PB3": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "D10": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "10": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "PWM10": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "PB4": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "D11": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "11": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "PWM11": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "PB5": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "D12": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "6"
        },
        "12": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "6"
        },
        "PWM12": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "6"
        },
        "PB6": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "6"
        },
        "D13": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "7"
        },
        "13": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "7"
        },
        "PWM13": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "7"
        },
        "PB7": {
            "ddr": "DDRB",
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "7"
        },
        "D37": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "37": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "PC0": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "D36": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "36": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "PC1": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "D35": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "35": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "PC2": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "D34": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "34": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "PC3": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "D33": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "33": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "PC4": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "D32": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "32": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "PC5": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "D31": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "6"
        },
        "31": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "6"
        },
        "PC6": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "6"
        },
        "D30": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "7"
        },
        "30": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "7"
        },
        "PC7": {
            "ddr": "DDRC",
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "7"
        },
        "SCL": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "0"
        },
        "PD0": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "0"
        },
        "SDA": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "1"
        },
        "PD1": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "1"
        },
        "RX1": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "PD2": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "TX1": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "PD3": {
            "ddr": "DDRC",
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "RX0": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "0"
        },
        "PE0": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "0"
        },
        "TX0": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "1"
        },
        "PE1": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "1"
        },
        "D5": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "3"
        },
        "5": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "3"
        },
        "PWM5": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "3"
        },
        "PE3": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "3"
        },
        "D2": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "4"
        },
        "2": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "4"
        },
        "PWM2": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "4"
        },
        "PE4": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "4"
        },
        "D3": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "5"
        },
        "3": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "5"
        },
        "PWM3": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "5"
        },
        "PE5": {
            "ddr": "DDRE",
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "5"
        },
        "A0": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "0"
        },
        "D54": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "0"
        },
        "54": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "0"
        },
        "PF0": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "0"
        },
        "A1": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "1"
        },
        "D55": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "1"
        },
        "55": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "1"
        },
        "PF1": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "1"
        },
        "A2": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "2"
        },
        "D56": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "2"
        },
        "56": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "2"
        },
        "PF2": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "2"
        },
        "A3": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "3"
        },
        "D57": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "3"
        },
        "57": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "3"
        },
        "PF3": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "3"
        },
        "A4": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "4"
        },
        "D58": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "4"
        },
        "58": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "4"
        },
        "PF4": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "4"
        },
        "A5": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "5"
        },
        "D59": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "5"
        },
        "59": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "5"
        },
        "PF5": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "5"
        },
        "A6": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "6"
        },
        "D60": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "6"
        },
        "60": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "6"
        },
        "PF6": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "6"
        },
        "A7": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "7"
        },
        "D61": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "7"
        },
        "61": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "7"
        },
        "PF7": {
            "ddr": "DDRF",
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "7"
        },
        "D41": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "0"
        },
        "41": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "0"
        },
        "PG0": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "0"
        },
        "D40": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "1"
        },
        "40": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "1"
        },
        "PG1": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "1"
        },
        "D39": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "2"
        },
        "39": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "2"
        },
        "PG2": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "2"
        },
        "D4": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "5"
        },
        "4": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "5"
        },
        "PWM4": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "5"
        },
        "PG5": {
            "ddr": "DDRG",
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "5"
        },
        "RX2": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "0"
        },
        "PH0": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "0"
        },
        "TX2": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "1"
        },
        "PH1": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "1"
        },
        "D6": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "3"
        },
        "6": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "3"
        },
        "PWM6": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "3"
        },
        "PH3": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "3"
        },
        "D7": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "4"
        },
        "7": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "4"
        },
        "PWM7": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "4"
        },
        "PH4": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "4"
        },
        "D8": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "5"
        },
        "8": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "5"
        },
        "PWM8": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "5"
        },
        "PH5": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "5"
        },
        "D9": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "6"
        },
        "9": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "6"
        },
        "PWM9": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "6"
        },
        "PH6": {
            "ddr": "DDRH",
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "6"
        },
        "RX3": {
            "ddr": "DDRJ",
            "wPort": "PORTJ",
            "rPort": "PINJ",
            "bit": "0"
        },
        "PJ0": {
            "ddr": "DDRJ",
            "wPort": "PORTJ",
            "rPort": "PINJ",
            "bit": "0"
        },
        "TX3": {
            "ddr": "DDRJ",
            "wPort": "PORTJ",
            "rPort": "PINJ",
            "bit": "1"
        },
        "PJ1": {
            "ddr": "DDRJ",
            "wPort": "PORTJ",
            "rPort": "PINJ",
            "bit": "1"
        },
        "D62": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "0"
        },
        "62": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "0"
        },
        "A8": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "0"
        },
        "PK0": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "0"
        },
        "D63": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "1"
        },
        "63": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "1"
        },
        "A9": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "1"
        },
        "PK1": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "1"
        },
        "D64": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "2"
        },
        "64": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "2"
        },
        "A10": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "2"
        },
        "PK2": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "2"
        },
        "D65": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "3"
        },
        "65": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "3"
        },
        "A11": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "3"
        },
        "PK3": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "3"
        },
        "D66": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "4"
        },
        "66": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "4"
        },
        "A12": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "4"
        },
        "PK4": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "4"
        },
        "D67": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "5"
        },
        "67": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "5"
        },
        "A13": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "5"
        },
        "PK5": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "5"
        },
        "D68": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "6"
        },
        "68": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "6"
        },
        "A14": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "6"
        },
        "PK6": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "6"
        },
        "D69": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "7"
        },
        "69": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "7"
        },
        "A15": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "7"
        },
        "PK7": {
            "ddr": "DDRK",
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "7"
        },
        "D49": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "0"
        },
        "49": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "0"
        },
        "PL0": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "0"
        },
        "D48": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "1"
        },
        "48": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "1"
        },
        "PL1": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "1"
        },
        "D47": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "2"
        },
        "47": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "2"
        },
        "PL2": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "2"
        },
        "D46": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "3"
        },
        "46": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "3"
        },
        "PL3": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "3"
        },
        "D45": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "4"
        },
        "45": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "4"
        },
        "PL4": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "4"
        },
        "D44": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "5"
        },
        "44": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "5"
        },
        "PL5": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "5"
        },
        "D43": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "6"
        },
        "43": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "6"
        },
        "PL6": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "6"
        },
        "D42": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "7"
        },
        "42": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "7"
        },
        "PL7": {
            "ddr": "DDRL",
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "7"
        }
    }
}
)";
#endif