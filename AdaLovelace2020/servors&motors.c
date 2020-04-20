//
// Created by Becky on 3/16/2020.
//
#include <stdio.h>

#include "servors&motors.h"
#include <variables.h>

//This file includes functions used for servos and motors

void servo(int servo, int desired_end_position) {
    servo_w_named_loops(servo, desired_end_position, 50, 10);
}

void servo_w_named_loops(int servo, int desired_end_position, int milliseconds_per_loop, int ticks) {
    int a;
    a = get_servo_position(servo);
    printf("%i \n", servo);
    printf("%i \n", desired_end_position);
    printf("%i \n", milliseconds_per_loop);
    printf("%i \n", ticks);
    if (a < desired_end_position) {
        while (a < desired_end_position) {
            a += ticks;
            set_servo_position(servo, a);
            msleep(milliseconds_per_loop);
        }
    }
    else {
        while (a > desired_end_position) {
            a -= ticks;
            set_servo_position(servo, a);
            msleep(milliseconds_per_loop);
        }
    }
    set_servo_position(servo, desired_end_position);
}