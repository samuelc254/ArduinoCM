#include "UNO_cpu_map.h"

void initPins()
{
ClrBit(Velocity_Pot_ddr, Velocity_Pot_bit) // input

ClrBit(Left_light_sensor_ddr, Left_light_sensor_bit) // input

ClrBit(Right_light_sensor_ddr, Right_light_sensor_bit) // input

ClrBit(Temperature_sensor_ddr, Temperature_sensor_bit) // input

ClrBit(Force_sensor_ddr, Force_sensor_bit) // input

ClrBit(Battery_voltage_ddr, Battery_voltage_bit) // input

SetBit(PWM_IN4_ddr, PWM_IN4_bit) // output

SetBit(PWM_Servo_ddr, PWM_Servo_bit) // output

SetBit(Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_ddr, Voce_pode_usar_nomes_hiper_ultra_mega_blaster_longos_bit) // output

ClrBit(Switch_button_ddr, Switch_button_bit) // input
SetBit(Switch_button_wPort, Switch_button_bit) // pullup

SetBit(LED1_ddr, LED1_bit) // output

SetBit(LED2_ddr, LED2_bit) // output

SetBit(PWM_IN1_ddr, PWM_IN1_bit) // output

SetBit(PWM_IN2_ddr, PWM_IN2_bit) // output

SetBit(P_ddr, P_bit) // output

SetBit(Pequenos_tambem_olha_ddr, Pequenos_tambem_olha_bit) // output

SetBit(PWM_IN3_ddr, PWM_IN3_bit) // output

ClrBit(RX_Bluetooth_ddr, RX_Bluetooth_bit) // input

SetBit(TX_Bluetooth_ddr, TX_Bluetooth_bit) // output

}