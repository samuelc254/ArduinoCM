#include "UNO_cpu_map.h"

void initPins()
{
SetBit(motor_ddr, motor_bit) // output

ClrBit(encoderA_ddr, encoderA_bit) // input
SetBit(encoderA_wPort, encoderA_bit) // pullup

ClrBit(encoderB_ddr, encoderB_bit) // input
SetBit(encoderB_wPort, encoderB_bit) // pullup

ClrBit(sensor_ddr, sensor_bit) // input

}