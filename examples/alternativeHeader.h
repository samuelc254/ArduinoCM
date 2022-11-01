#ifndef DEFINES_H
#define DEFINES_H
#define cpu_map_for_MEGA

#define Velocity_Pot_wPort PORTF
#define Velocity_Pot_rPort PINF
#define Velocity_Pot_bit 0

#define Left_light_sensor_wPort PORTF
#define Left_light_sensor_rPort PINF
#define Left_light_sensor_bit 1

#define Right_light_sensor_wPort PORTF
#define Right_light_sensor_rPort PINF
#define Right_light_sensor_bit 2

#define Temperature_sensor_wPort PORTF
#define Temperature_sensor_rPort PINF
#define Temperature_sensor_bit 3

#define Force_sensor_wPort PORTF
#define Force_sensor_rPort PINF
#define Force_sensor_bit 4

#define Battery_voltage_wPort PORTF
#define Battery_voltage_rPort PINF
#define Battery_voltage_bit 5

#define PWM_IN4_wPort PORTB
#define PWM_IN4_rPort PINB
#define PWM_IN4_bit 4

#define PWM_Servo_wPort PORTB
#define PWM_Servo_rPort PINB
#define PWM_Servo_bit 5

#define Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_wPort PORTB
#define Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_rPort PINB
#define Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_bit 6

#define Switch_button_wPort PORTE
#define Switch_button_rPort PINE
#define Switch_button_bit 4

#define LED1_wPort PORTE
#define LED1_rPort PINE
#define LED1_bit 5

#define LED2_wPort PORTG
#define LED2_rPort PING
#define LED2_bit 5

#define PWM_IN1_wPort PORTE
#define PWM_IN1_rPort PINE
#define PWM_IN1_bit 3

#define PWM_IN2_wPort PORTH
#define PWM_IN2_rPort PINH
#define PWM_IN2_bit 3

#define P_wPort PORTH
#define P_rPort PINH
#define P_bit 4

#define Pequenos_tambem_olha_wPort PORTH
#define Pequenos_tambem_olha_rPort PINH
#define Pequenos_tambem_olha_bit 5

#define PWM_IN3_wPort PORTH
#define PWM_IN3_rPort PINH
#define PWM_IN3_bit 6

#define I2C_SCL_Gyro_wPort PORTD
#define I2C_SCL_Gyro_rPort PIND
#define I2C_SCL_Gyro_bit 0

#define I2C_SDA_Gyro_wPort PORTD
#define I2C_SDA_Gyro_rPort PIND
#define I2C_SDA_Gyro_bit 1


#define SetBit(RES, BIT)(RES |= (1 << BIT)) // Set BIT in RES to HIGH
#define ClrBit(RES, BIT)(RES &= ~ (1 << BIT)) // Set BIT in RES to LOW
#define TstBit(RES, BIT)(RES &  (1 << BIT)) // Test BIT in RES and return 0 or 1
#define InvBit(RES, BIT)(RES ^= (1 << BIT)) // Invert BIT in RES (0 to 1 and 1 to 0)
#define WriteBit(RES, BIT, VAL) (VAL)?SetBit(RES, BIT):ClrBit(RES, BIT) // Write VAL in BIT in RES (0 or 1)

#endif