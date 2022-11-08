#include "UNO_cpu_map.h"

void initPins(){

ClrBit(Velocity_Pot_ddr, Velocity_Pot_bit) // define the pin as input

ClrBit(Left_light_sensor_ddr, Left_light_sensor_bit) // define the pin as input

ClrBit(Right_light_sensor_ddr, Right_light_sensor_bit) // define the pin as input

ClrBit(Temperature_sensor_ddr, Temperature_sensor_bit) // define the pin as input

ClrBit(Force_sensor_ddr, Force_sensor_bit) // define the pin as input

ClrBit(Battery_voltage_ddr, Battery_voltage_bit) // define the pin as input

SetBit(PWM_IN4_ddr, PWM_IN4_bit) // define the pin as output

SetBit(PWM_Servo_ddr, PWM_Servo_bit) // define the pin as output

SetBit(Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_ddr, Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_bit) // define the pin as output

ClrBit(Switch_button_ddr, Switch_button_bit) // define the pin as input
SetBit(Switch_button_wPort, Switch_button_bit) // define the pin as pullup

SetBit(LED1_ddr, LED1_bit) // define the pin as output

SetBit(LED2_ddr, LED2_bit) // define the pin as output

SetBit(PWM_IN1_ddr, PWM_IN1_bit) // define the pin as output

SetBit(PWM_IN2_ddr, PWM_IN2_bit) // define the pin as output

SetBit(P_ddr, P_bit) // define the pin as output

SetBit(Pequenos_tambem_olha_ddr, Pequenos_tambem_olha_bit) // define the pin as output

SetBit(PWM_IN3_ddr, PWM_IN3_bit) // define the pin as output

ClrBit(RX_Bluetooth_ddr, RX_Bluetooth_bit) // define the pin as input

SetBit(TX_Bluetooth_ddr, TX_Bluetooth_bit) // define the pin as output

}