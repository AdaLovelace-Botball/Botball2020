//
// Created by siliconninja on 5/24/2020.
//

#ifndef BOTBALL2020_GYRO_H
#define BOTBALL2020_GYRO_H

void calibrate_gyro();

void declare_motors(int lmotor, int rmotor);
void calibrate_gyro();
void cg();
void turn_with_gyro(int left_wheel_speed, int right_wheel_speed, double targetTheta);
void drive_with_gyro(int speed, double time);
void simple_drive_with_gyro(int speed, double time);


#endif //BOTBALL2020_GYRO_H
