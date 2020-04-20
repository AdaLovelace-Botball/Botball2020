//
// Created by Becky on 3/16/2020.
//

#ifndef UNTITLED_SERVORS_MOTORS_H
#define UNTITLED_SERVORS_MOTORS_H

//This file includes functions used for servos and motors

void servo(int servo, int desired_end_position);
void servo_w_named_loops(int servo, int desired_end_position, int milliseconds_per_loop, int ticks);

#endif //UNTITLED_SERVORS_MOTORS_H
