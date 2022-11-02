#ifndef DEFINES_H
#define DEFINES_H
#define cpu_map_for_UNO

#define Velocity_Pot_ddr DDRC
#define Velocity_Pot_wPort PORTC
#define Velocity_Pot_rPort PINC
#define Velocity_Pot_bit 0

#define Left_light_sensor_ddr DDRC
#define Left_light_sensor_wPort PORTC
#define Left_light_sensor_rPort PINC
#define Left_light_sensor_bit 1

#define Right_light_sensor_ddr DDRC
#define Right_light_sensor_wPort PORTC
#define Right_light_sensor_rPort PINC
#define Right_light_sensor_bit 2

#define Temperature_sensor_ddr DDRC
#define Temperature_sensor_wPort PORTC
#define Temperature_sensor_rPort PINC
#define Temperature_sensor_bit 3

#define Force_sensor_ddr DDRC
#define Force_sensor_wPort PORTC
#define Force_sensor_rPort PINC
#define Force_sensor_bit 4

#define Battery_voltage_ddr DDRC
#define Battery_voltage_wPort PORTC
#define Battery_voltage_rPort PINC
#define Battery_voltage_bit 5

#define PWM_IN4_ddr DDRB
#define PWM_IN4_wPort PORTB
#define PWM_IN4_rPort PINB
#define PWM_IN4_bit 2

#define PWM_Servo_ddr DDRB
#define PWM_Servo_wPort PORTB
#define PWM_Servo_rPort PINB
#define PWM_Servo_bit 3

#define Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_ddr DDRB
#define Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_wPort PORTB
#define Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_rPort PINB
#define Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_bit 4

#define Switch_button_ddr DDRC
#define Switch_button_wPort PORTD
#define Switch_button_rPort PIND
#define Switch_button_bit 2

#define LED1_ddr DDRC
#define LED1_wPort PORTD
#define LED1_rPort PIND
#define LED1_bit 3

#define LED2_ddr DDRC
#define LED2_wPort PORTD
#define LED2_rPort PIND
#define LED2_bit 4

#define PWM_IN1_ddr DDRC
#define PWM_IN1_wPort PORTD
#define PWM_IN1_rPort PIND
#define PWM_IN1_bit 5

#define PWM_IN2_ddr DDRC
#define PWM_IN2_wPort PORTD
#define PWM_IN2_rPort PIND
#define PWM_IN2_bit 6

#define P_ddr DDRC
#define P_wPort PORTD
#define P_rPort PIND
#define P_bit 7

#define Pequenos_tambem_olha_ddr DDRB
#define Pequenos_tambem_olha_wPort PORTB
#define Pequenos_tambem_olha_rPort PINB
#define Pequenos_tambem_olha_bit 0

#define PWM_IN3_ddr DDRB
#define PWM_IN3_wPort PORTB
#define PWM_IN3_rPort PINB
#define PWM_IN3_bit 1

#define RX_Bluetooth_ddr DDRC
#define RX_Bluetooth_wPort PORTD
#define RX_Bluetooth_rPort PIND
#define RX_Bluetooth_bit 0

#define I2C_SCL_Gyro_ddr DDRC
#define I2C_SCL_Gyro_wPort PORTC
#define I2C_SCL_Gyro_rPort PINC
#define I2C_SCL_Gyro_bit 5

#define I2C_SDA_Gyro_ddr DDRC
#define I2C_SDA_Gyro_wPort PORTC
#define I2C_SDA_Gyro_rPort PINC
#define I2C_SDA_Gyro_bit 4

#define TX_Bluetooth_ddr DDRC
#define TX_Bluetooth_wPort PORTD
#define TX_Bluetooth_rPort PIND
#define TX_Bluetooth_bit 1


#define SetBit(RES, BIT)(RES |= (1 << BIT)) // Set BIT in RES to HIGH
#define ClrBit(RES, BIT)(RES &= ~ (1 << BIT)) // Set BIT in RES to LOW
#define TstBit(RES, BIT)(RES &  (1 << BIT)) // Test BIT in RES and return 0 or 1
#define InvBit(RES, BIT)(RES ^= (1 << BIT)) // Invert BIT in RES (0 to 1 and 1 to 0)
#define WriteBit(RES, BIT, VAL) (VAL)?SetBit(RES, BIT):ClrBit(RES, BIT) // Write VAL in BIT in RES (0 or 1)

#endif