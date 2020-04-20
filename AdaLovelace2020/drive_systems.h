//
// Created by Becky on 3/16/2020.
//

#ifndef UNTITLED_DRIVE_SYSTEMS_H
#define UNTITLED_DRIVE_SYSTEMS_H

//This file includes defines used for movement involving wheels

//movement via time
void forward_t(int speed, float seconds);
void backward_t(int speed, float seconds);
void right_t(int speed, float seconds);
void left_t(int speed, float seconds);

//movement via distance
void forward_d(int speed, float distance);
void backward_d(int speed, float distance);
void right_d(int speed, float distance);
void left_d(int speed, float distance);

//movement indefinitely
void forward_i(int speed);
void backward_i(int speed);

//specific movement
void drive_w_arm(float seconds, int desired_arm_position);

#endif //UNTITLED_DRIVE_SYSTEMS_H
