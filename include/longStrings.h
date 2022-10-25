#ifndef LONGSTRINGS_H
#define LONGSTRINGS_H

const char *macros = R"(
#define SetBit(RES, BIT)(RES |= (1 << BIT)) // Por BIT em nível alto
#define ClrBit(RES, BIT)(RES &= ~ (1 << BIT)) // Por BIT em nível baixo
#define TstBit(RES, BIT)(RES &  (1 << BIT)) // testar BIT, retorna 0 ou 1
#define CplBit(RES, BIT)(RES ^= (1 << BIT)) // Inverter estado do BIT
#define WriteBit(RES, BIT, VAL) (VAL)?SetBit(RES, BIT):ClrBit(RES, BIT) // Escrever VAL no BIT

#endif)";

const char *boardsJson = R"( 
{
    "0":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "0"
    },
    "1":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "1"
    },
    "2":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "2"
    },
    "3":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "3"
    },
    "4":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "4"
    },
    "5":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "5"
    },
    "6":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "6"
    },
    "7":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "7"
    },
    "8":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "0"
    },
    "9":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "1"
    },
    "10":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "2"
    },
    "11":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "3"
    },
    "12":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "4"
    },
    "13":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "5"
    },
    "14":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "0"
    },
    "15":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "1"
    },
    "16":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "2"
    },
    "17":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "3"
    },
    "18":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "4"
    },
    "19":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "5"
    },
    "A0":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "0"
    },
    "A1":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "1"
    },
    "A2":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "2"
    },
    "A3":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "3"
    },
    "A4":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "4"
    },
    "A5":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "5"
    },
    "PD0":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "0"
    },
    "PD1":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "1"
    },
    "PD2":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "2"
    },
    "PD3":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "3"
    },
    "PD4":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "4"
    },
    "PD5":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "5"
    },
    "PD6":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "6"
    },
    "PD7":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "7"
    },
    "PB0":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "0"
    },
    "PB1":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "1"
    },
    "PB2":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "2"
    },
    "PB3":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "3"
    },
    "PB4":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "4"
    },
    "PB5":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "5"
    },
    "PC0":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "0"
    },
    "PC1":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "1"
    },
    "PC2":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "2"
    },
    "PC3":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "3"
    },
    "PC4":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "4"
    },
    "PC5":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "5"
    },
    "D0":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "0"
    },
    "D1":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "1"
    },
    "D2":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "2"
    },
    "D3":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "3"
    },
    "D4":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "4"
    },
    "D5":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "5"
    },
    "D6":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "6"
    },
    "D7":
    {
        "wPort": "PORTD",
        "rPort": "PIND",
        "bit": "7"
    },
    "D8":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "0"
    },
    "D9":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "1"
    },
    "D10":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "2"
    },
    "D11":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "3"
    },
    "D12":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "4"
    },
    "D13":
    {
        "wPort": "PORTB",
        "rPort": "PINB",
        "bit": "5"
    },
    "D14":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "0"
    },
    "D15":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "1"
    },
    "D16":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "2"
    },
    "D17":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "3"
    },
    "D18":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "4"
    },
    "D19":
    {
        "wPort": "PORTC",
        "rPort": "PINC",
        "bit": "5"
    }
}
)";

#endif