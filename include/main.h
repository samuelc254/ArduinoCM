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

map<string, char> specialCharacters;

void startMap();

void removeAccents(string str, char *out);

int main(int argc, char *argv[]);

const char *macros = R"(
#define SetBit(RES, BIT)(RES |= (1 << BIT)) // Set BIT in RES to HIGH
#define ClrBit(RES, BIT)(RES &= ~ (1 << BIT)) // Set BIT in RES to LOW
#define TstBit(RES, BIT)(RES &  (1 << BIT)) // Test BIT in RES and return 0 or 1
#define InvBit(RES, BIT)(RES ^= (1 << BIT)) // Invert BIT in RES (0 to 1 and 1 to 0)
#define WriteBit(RES, BIT, VAL) (VAL)?SetBit(RES, BIT):ClrBit(RES, BIT) // Write VAL in BIT in RES (0 or 1)

#endif)";

const char *configString = R"( 
{
    "UNO": {
        "8": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "D8": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "PB0": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "9": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "D9": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "PB1": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "10": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "D10": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "PB2": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "SS": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "11": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "D11": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "PB3": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "MOSI": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "12": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "D12": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "PB4": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "MISO": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "13": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "D13": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "PB5": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "SCK": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "14": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "D14": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "PC0": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "A0": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "15": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "D15": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "PC1": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "A1": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "16": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "D16": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "PC2": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "A2": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "17": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "D17": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "PC3": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "A3": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "18": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "D18": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "PC4": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "A4": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "SDA": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "19": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "D19": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "PC5": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "A5": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "SCL": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "0": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "0"
        },
        "D0": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "0"
        },
        "PD0": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "6"
        },
        "RX": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "0"
        },
        "1": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "1"
        },
        "D1": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "1"
        },
        "PD1": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "7"
        },
        "TX": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "1"
        },
        "2": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "D2": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "PD2": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "INT0": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "3": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "D3": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "PD3": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "INT1": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "4": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "4"
        },
        "D4": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "4"
        },
        "PD4": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "4"
        },
        "5": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "5"
        },
        "D5": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "5"
        },
        "PD5": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "5"
        },
        "6": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "6"
        },
        "D6": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "6"
        },
        "7": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "7"
        },
        "D7": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "7"
        }
    }
}
)";
#endif