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
    },
    "MEGA": {
        "D22": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "0"
        },
        "22": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "0"
        },
        "PA0": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "0"
        },
        "D23": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "1"
        },
        "23": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "1"
        },
        "PA1": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "1"
        },
        "D24": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "2"
        },
        "24": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "2"
        },
        "PA2": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "2"
        },
        "D25": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "3"
        },
        "25": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "3"
        },
        "PA3": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "3"
        },
        "D26": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "4"
        },
        "26": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "4"
        },
        "PA4": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "4"
        },
        "D27": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "5"
        },
        "27": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "5"
        },
        "PA5": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "5"
        },
        "D28": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "6"
        },
        "28": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "6"
        },
        "PA6": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "6"
        },
        "D29": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "7"
        },
        "29": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "7"
        },
        "PA7": {
            "wPort": "PORTA",
            "rPort": "PINA",
            "bit": "7"
        },
        "D53": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "53": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "SS": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "PB0": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "0"
        },
        "D52": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "52": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "SCK": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "PB1": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "1"
        },
        "D51": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "51": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "MOSI": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "PB2": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "2"
        },
        "D50": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "50": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "MISO": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "PB3": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "3"
        },
        "D10": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "10": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "PWM10": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "PB4": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "4"
        },
        "D11": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "11": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "PWM11": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "PB5": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "5"
        },
        "D12": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "6"
        },
        "12": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "6"
        },
        "PWM12": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "6"
        },
        "PB6": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "6"
        },
        "D13": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "7"
        },
        "13": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "7"
        },
        "PWM13": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "7"
        },
        "PB7": {
            "wPort": "PORTB",
            "rPort": "PINB",
            "bit": "7"
        },
        "D37": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "37": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "PC0": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "0"
        },
        "D36": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "36": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "PC1": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "1"
        },
        "D35": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "35": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "PC2": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "2"
        },
        "D34": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "34": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "PC3": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "3"
        },
        "D33": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "33": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "PC4": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "4"
        },
        "D32": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "32": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "PC5": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "5"
        },
        "D31": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "6"
        },
        "31": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "6"
        },
        "PC6": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "6"
        },
        "D30": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "7"
        },
        "30": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "7"
        },
        "PC7": {
            "wPort": "PORTC",
            "rPort": "PINC",
            "bit": "7"
        },
        "SCL": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "0"
        },
        "PD0": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "0"
        },
        "SDA": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "1"
        },
        "PD1": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "1"
        },
        "RX1": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "PD2": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "2"
        },
        "TX1": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "PD3": {
            "wPort": "PORTD",
            "rPort": "PIND",
            "bit": "3"
        },
        "RX0": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "0"
        },
        "PE0": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "0"
        },
        "TX0": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "1"
        },
        "PE1": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "1"
        },
        "D5": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "3"
        },
        "5": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "3"
        },
        "PWM5": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "3"
        },
        "PE3": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "3"
        },
        "D2": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "4"
        },
        "2": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "4"
        },
        "PWM2": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "4"
        },
        "PE4": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "4"
        },
        "D3": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "5"
        },
        "3": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "5"
        },
        "PWM3": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "5"
        },
        "PE5": {
            "wPort": "PORTE",
            "rPort": "PINE",
            "bit": "5"
        },
        "A0": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "0"
        },
        "D54": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "0"
        },
        "54": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "0"
        },
        "PF0": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "0"
        },
        "A1": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "1"
        },
        "D55": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "1"
        },
        "55": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "1"
        },
        "PF1": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "1"
        },
        "A2": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "2"
        },
        "D56": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "2"
        },
        "56": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "2"
        },
        "PF2": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "2"
        },
        "A3": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "3"
        },
        "D57": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "3"
        },
        "57": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "3"
        },
        "PF3": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "3"
        },
        "A4": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "4"
        },
        "D58": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "4"
        },
        "58": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "4"
        },
        "PF4": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "4"
        },
        "A5": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "5"
        },
        "D59": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "5"
        },
        "59": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "5"
        },
        "PF5": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "5"
        },
        "A6": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "6"
        },
        "D60": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "6"
        },
        "60": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "6"
        },
        "PF6": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "6"
        },
        "A7": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "7"
        },
        "D61": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "7"
        },
        "61": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "7"
        },
        "PF7": {
            "wPort": "PORTF",
            "rPort": "PINF",
            "bit": "7"
        },
        "D41": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "0"
        },
        "41": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "0"
        },
        "PG0": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "0"
        },
        "D40": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "1"
        },
        "40": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "1"
        },
        "PG1": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "1"
        },
        "D39": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "2"
        },
        "39": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "2"
        },
        "PG2": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "2"
        },
        "D4": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "5"
        },
        "4": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "5"
        },
        "PWM4": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "5"
        },
        "PG5": {
            "wPort": "PORTG",
            "rPort": "PING",
            "bit": "5"
        },
        "RX2": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "0"
        },
        "PH0": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "0"
        },
        "TX2": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "1"
        },
        "PH1": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "1"
        },
        "D6": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "3"
        },
        "6": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "3"
        },
        "PWM6": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "3"
        },
        "PH3": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "3"
        },
        "D7": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "4"
        },
        "7": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "4"
        },
        "PWM7": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "4"
        },
        "PH4": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "4"
        },
        "D8": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "5"
        },
        "8": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "5"
        },
        "PWM8": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "5"
        },
        "PH5": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "5"
        },
        "D9": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "6"
        },
        "9": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "6"
        },
        "PWM9": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "6"
        },
        "PH6": {
            "wPort": "PORTH",
            "rPort": "PINH",
            "bit": "6"
        },
        "RX3": {
            "wPort": "PORTJ",
            "rPort": "PINJ",
            "bit": "0"
        },
        "PJ0": {
            "wPort": "PORTJ",
            "rPort": "PINJ",
            "bit": "0"
        },
        "TX3": {
            "wPort": "PORTJ",
            "rPort": "PINJ",
            "bit": "1"
        },
        "PJ1": {
            "wPort": "PORTJ",
            "rPort": "PINJ",
            "bit": "1"
        },
        "D62": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "0"
        },
        "62": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "0"
        },
        "A8": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "0"
        },
        "PK0": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "0"
        },
        "D63": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "1"
        },
        "63": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "1"
        },
        "A9": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "1"
        },
        "PK1": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "1"
        },
        "D64": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "2"
        },
        "64": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "2"
        },
        "A10": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "2"
        },
        "PK2": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "2"
        },
        "D65": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "3"
        },
        "65": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "3"
        },
        "A11": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "3"
        },
        "PK3": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "3"
        },
        "D66": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "4"
        },
        "66": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "4"
        },
        "A12": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "4"
        },
        "PK4": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "4"
        },
        "D67": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "5"
        },
        "67": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "5"
        },
        "A13": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "5"
        },
        "PK5": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "5"
        },
        "D68": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "6"
        },
        "68": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "6"
        },
        "A14": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "6"
        },
        "PK6": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "6"
        },
        "D69": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "7"
        },
        "69": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "7"
        },
        "A15": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "7"
        },
        "PK7": {
            "wPort": "PORTK",
            "rPort": "PINK",
            "bit": "7"
        },
        "D49": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "0"
        },
        "49": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "0"
        },
        "PL0": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "0"
        },
        "D48": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "1"
        },
        "48": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "1"
        },
        "PL1": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "1"
        },
        "D47": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "2"
        },
        "47": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "2"
        },
        "PL2": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "2"
        },
        "D46": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "3"
        },
        "46": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "3"
        },
        "PL3": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "3"
        },
        "D45": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "4"
        },
        "45": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "4"
        },
        "PL4": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "4"
        },
        "D44": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "5"
        },
        "44": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "5"
        },
        "PL5": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "5"
        },
        "D43": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "6"
        },
        "43": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "6"
        },
        "PL6": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "6"
        },
        "D42": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "7"
        },
        "42": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "7"
        },
        "PL7": {
            "wPort": "PORTL",
            "rPort": "PINL",
            "bit": "7"
        }
    }
}
)";
#endif