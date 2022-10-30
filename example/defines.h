#ifndef DEFINES_H
#define DEFINES_H

#define Velocity_Pot_wPort PORTC
#define Velocity_Pot_rPort PINC
#define Velocity_Pot_bit 0

#define Left_light_sensor_wPort PORTC
#define Left_light_sensor_rPort PINC
#define Left_light_sensor_bit 1

#define Right_light_sensor_wPort PORTC
#define Right_light_sensor_rPort PINC
#define Right_light_sensor_bit 2

#define Temperature_sensor_wPort PORTC
#define Temperature_sensor_rPort PINC
#define Temperature_sensor_bit 3

#define Force_sensor_wPort PORTC
#define Force_sensor_rPort PINC
#define Force_sensor_bit 4

#define Battery_voltage_wPort PORTC
#define Battery_voltage_rPort PINC
#define Battery_voltage_bit 5

#define PWM_IN4_wPort PORTB
#define PWM_IN4_rPort PINB
#define PWM_IN4_bit 2

#define PWM_Servo_wPort PORTB
#define PWM_Servo_rPort PINB
#define PWM_Servo_bit 3

#define Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_wPort PORTB
#define Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_rPort PINB
#define Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_bit 4

#define Switch_button_wPort PORTD
#define Switch_button_rPort PIND
#define Switch_button_bit 2

#define LED1_wPort PORTD
#define LED1_rPort PIND
#define LED1_bit 3

#define LED2_wPort PORTD
#define LED2_rPort PIND
#define LED2_bit 4

#define PWM_IN1_wPort PORTD
#define PWM_IN1_rPort PIND
#define PWM_IN1_bit 5

#define PWM_IN2_wPort PORTD
#define PWM_IN2_rPort PIND
#define PWM_IN2_bit 6

#define P_wPort PORTD
#define P_rPort PIND
#define P_bit 7

#define Pequenos_tambem_olha_wPort PORTB
#define Pequenos_tambem_olha_rPort PINB
#define Pequenos_tambem_olha_bit 0

#define PWM_IN3_wPort PORTB
#define PWM_IN3_rPort PINB
#define PWM_IN3_bit 1


#define SetBit(RES, BIT)(RES |= (1 << BIT)) // Por BIT em nível alto
#define ClrBit(RES, BIT)(RES &= ~ (1 << BIT)) // Por BIT em nível baixo
#define TstBit(RES, BIT)(RES &  (1 << BIT)) // testar BIT, retorna 0 ou 1
#define CplBit(RES, BIT)(RES ^= (1 << BIT)) // Inverter estado do BIT
#define WriteBit(RES, BIT, VAL) (VAL)?SetBit(RES, BIT):ClrBit(RES, BIT) // Escrever VAL no BIT

#endif