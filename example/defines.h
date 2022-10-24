#ifndef DEFINES_H
#define DEFINES_H

#define LED_wPort PORTB
#define LED_rPort PINB
#define LED_bit 5

#define TRAVA_wPort PORTB
#define TRAVA_rPort PINB
#define TRAVA_bit 4

#define MOTOR_wPort PORTB
#define MOTOR_rPort PINB
#define MOTOR_bit 3

#define SENSOR_wPort PORTC
#define SENSOR_rPort PINC
#define SENSOR_bit 4

#define bimanual_1_wPort PORTD
#define bimanual_1_rPort PIND
#define bimanual_1_bit 2

#define bimanual_2_wPort PORTD
#define bimanual_2_rPort PIND
#define bimanual_2_bit 3

#define start_wPort PORTD
#define start_rPort PIND
#define start_bit 7

#define Manual_wPort PORTB
#define Manual_rPort PINB
#define Manual_bit 2

#define SetBit(RES, BIT)(RES |= (1 << BIT)) // Por BIT em nível alto
#define ClrBit(RES, BIT)(RES &= ~ (1 << BIT)) // Por BIT em nível baixo
#define TstBit(RES, BIT)(RES &  (1 << BIT)) // testar BIT, retorna 0 ou 1
#define CplBit(RES, BIT)(RES ^= (1 << BIT)) // Inverter estado do BIT
#define WriteBit(RES, BIT, VAL) (VAL)?SetBit(RES, BIT):ClrBit(RES, BIT) // Escrever VAL no BIT

#endif