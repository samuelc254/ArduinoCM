#ifndef UNO_cpu_map_H
#define UNO_cpu_map_H

#define motor_ddr DDRB
#define motor_wPort PORTB
#define motor_rPort PINB
#define motor_bit 5

#define encoderA_ddr DDRD
#define encoderA_wPort PORTD
#define encoderA_rPort PIND
#define encoderA_bit 2

#define encoderB_ddr DDRD
#define encoderB_wPort PORTD
#define encoderB_rPort PIND
#define encoderB_bit 3

#define sensor_ddr DDRC
#define sensor_wPort PORTC
#define sensor_rPort PINC
#define sensor_bit 0

#define SetBit(RES, BIT)(RES |= (1 << BIT)) // Set BIT in RES to HIGH
#define ClrBit(RES, BIT)(RES &= ~ (1 << BIT)) // Set BIT in RES to LOW
#define TstBit(RES, BIT)(RES &  (1 << BIT)) // Test BIT in RES and return 0 or 1
#define InvBit(RES, BIT)(RES ^= (1 << BIT)) // Invert BIT in RES (0 to 1 and 1 to 0)
#define WriteBit(RES, BIT, VAL) (VAL)?SetBit(RES, BIT):ClrBit(RES, BIT) // Write VAL in BIT in RES (0 or 1)

void initPins();

#endif