//
// Created by Becky on 3/16/2020.
//
#include <stdio.h>

#include "drive_systems.h"
#include "drive_systems.h"
#include <kipr/wombat.h>
#include <servos&motors.h>
#include "variables.h"

//This file includes functions used for movement involving wheels
//Functions include: forward_t, backward_t, left_t, right_t, forward_d, backward_d, left_d, right_d

void forward_t(int speed, float seconds) {
    forward_i(speed);
    msleep(seconds * 1000);
    off(right_motor);
    off(left_motor);
}

void backward_t(int speed, float seconds) {
    backward_i(speed);
    msleep(seconds * 1000);
    off(right_motor);
    off(left_motor);
}

void right_t(int speed, float seconds) {
    motor(right_motor, -speed);
    motor(left_motor, speed);
    msleep(seconds * 1000);
    off(right_motor);
    off(left_motor);
}

void left_t(int speed, float seconds) {
    right_t(-speed, seconds);
}

void forward_d(int speed, float inches) {
}

void backward_d(int speed, float inches) {
}

void left_d(int speed, float inches) {
}

void right_d(int speed, float inches) {
}

void forward_i(int speed) {
    motor(right_motor, speed - 10);
    motor(left_motor, speed);
}

void backward_i(int speed) {
    motor(right_motor, -speed);
    motor(left_motor, -speed - 20);
}

void drive_w_arm(float seconds, int desired_arm_position) {
    int milliseconds_per_loop;
    int ticks;
    int total_ticks;
    int current_arm_value;
    int loops;
    current_arm_value = get_servo_position(arm);
    ticks = 20;
    total_ticks = fabs(current_arm_value - desired_arm_position);
    loops = total_ticks / ticks;
    milliseconds_per_loop = ((seconds * 1000) / loops);

    forward_i(v_slow);
    printf("Hello World\n");
    servo_w_named_loops(arm, desired_arm_position, milliseconds_per_loop, ticks);
    printf("Hello World\n");
    ao();
}