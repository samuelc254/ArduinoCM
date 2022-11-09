#include "MEGA_cpu_map.h"

void initPins()
{
SetBit(fr_motor_step_ddr, fr_motor_step_bit) // output

SetBit(fr_motor_dir_ddr, fr_motor_dir_bit) // output

SetBit(bl_motor_step_ddr, bl_motor_step_bit) // output

SetBit(fl_motor_step_ddr, fl_motor_step_bit) // output

SetBit(br_motor_step_ddr, br_motor_step_bit) // output

SetBit(bl_motor_dir_ddr, bl_motor_dir_bit) // output

SetBit(fl_motor_dir_ddr, fl_motor_dir_bit) // output

SetBit(br_motor_dir_ddr, br_motor_dir_bit) // output

SetBit(motors_enable_ddr, motors_enable_bit) // output

}