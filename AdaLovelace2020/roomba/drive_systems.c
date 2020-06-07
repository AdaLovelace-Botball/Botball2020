//
// Created by Jacob on 5/15/2020.
//
#include "gyro.h"
#include <kipr.h>
// Gyroscope only works on the Roomba (Wallaby)

// INFO this uses the gyroscope on the Wallaby so it's more accurate
// speed is in ticks/second (0 to 1500)
// speed cannot be negative because we want it to have positive time
// TODO write a unit test to reject negative values
// (Because of the mav function in simple_drive_with_gyro:
// https://files.kipr.org/wallaby/wallaby_doc/group__motor.html#gabd36f01986c363f70d86c7a768ae1348)
void forward_d(int speed, float inches) {
    simple_drive_with_gyro(speed, inches/speed);
}

// INFO this uses the gyroscope on the Wallaby so it's more accurate
// speed is in ticks/second (0 to 1500)
// speed cannot be negative because we want it to have positive time
// TODO write a unit test to reject negative values
void backward_d(int speed, float inches) {
    simple_drive_with_gyro(-speed, inches/speed);
}

void left_d(int speed, float inches) {
}

void right_d(int speed, float inches) {
}