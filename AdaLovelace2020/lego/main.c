#include <stdio.h>

#include "camera.h"
#include "drive_systems.h"
#include "sensors.h"
#include <servos&motors.h>
#include "utilities.h"
#include "variables.h"

//                                        !!!!!IMPORTANT SETUP NOTES!!!!!

//LEFT MOTOR needs to have the black facing away from the wombat, while the RIGHT MOTOR needs to have the black
//facing toward the wombat

// INFO the robot should be in the start position.
// For later (if needed): Recalculate distance to the ramp if it is in a different position.
void move_to_ramp() {
    forward_d(60, 2);
}

void move_antennae(){
    // attenae
    backward_t(60, 1.5);
    right_t(60, 0.5);
    backward_t(60, 1);
    right_t(60, 0.5);
}

void move_toward_mountain() {
    // moving toward the mountain
    servo(arm, 600);
    msleep(1000);
    forward_t(30, 0.1);
    msleep(1000);
    servo(arm, 1200);
    msleep(1000);
    forward_t(30, 0.1);
    msleep(1000);
    servo(arm, arm_down);
    msleep(1000);
    forward_t(30, 0.1);
}

int main()
{
    printf("Hello World\n");

    set_servo_position(claw, butterfly);
    set_servo_position(arm, uppity_up);
    printf("Hello World\n");

    enable_servos();
    printf("Hello World\n");

    move_to_ramp();
    //move_toward_mountain();

    msleep(5000);
    printf("Hello World\n");

    //drive_w_arm(5, arm_down);

    disable_servos();
    return 0;
}
