//
// Created by Becky on 5/15/2020.
//

#include <../kipr/wallaby.h>
#include "../include/Robot.h"
#include "2019-Defines.h"
//The first team to yeet a botguy and succeed
extern int TOGGLE;


void calibration();

int is_correct_position(point2 center);
int is_on_fire(int tries);

void right_tower();
void middle_tower();
void left_tower();

void left_right();
void left_middle();
void middle_right();

void all_towers();

void left_lwcu();
void middle_lwcu();
void right_lwcu();

void find_fire(int tries, int pictures);

int main() //Calls all functiones
{
    //TOGGLE=TRUE;
    TOGGLE=FALSE;
    printf("Create connecting...\n");
    create_connect();
    printf("Create Connected!\n");
    set_servo_position(lift, lift_up);
    set_servo_position(claw, claw_start);
    set_servo_position(sweeper, sweeper_close);
    enable_servos();
    start_camera();
    //start();
    msleep(2000);
    create_full();
    //calibration();
    //press_a();
    msleep(1000);
    find_fire(20, 20);
    //left_middle();
    //left_right();
    //middle_right();
    //all_towers();
    //large_water();
    printf("Hoi\n");
    disable_servos();
    create_stop();
    create_safe();
    create_disconnect();
    return 0;
}

void calibration() {
    /*servo();
    msleep(1000);
    servo();
    msleep(1000);
    servo();
    msleep(1000);
    servo();
    msleep(1000);
    forward_with_encoder();
    msleep(1000);
    forward_with_encoder();
    msleep(1000);*/
}

int is_correct_position(point2 center) {
    point2 expected_center = {EXPECTED_X, EXPECTED_Y};
    float radius;
    radius = sqrt(pow(expected_center.x - center.x, 2) + pow(expected_center.y - center.y, 2));
    if (radius <= MAX_DISTANCE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int is_on_fire(int tries) {
    int yellow_objects, /*red_objects, j,*/ n, k, area;
    point2 center;
    camera_update();
    yellow_objects = get_object_count(YELLOW);
    for (n = 0; n < tries; n = n + 1) {
        for (k = 0; k < yellow_objects; k = k + 1) {
            center = get_object_center(YELLOW, k);
            area = get_object_area(YELLOW, k);
            printf("yellow %3d %3d %5d\n", center.x, center.y, area);
            if(is_correct_position(center) == TRUE) {
                if (area >= YELLOW_AREA) {
                    return TRUE;
                    //check red code
                    /*camera_update();
                    red_objects = get_object_count(RED);
                    for (j = 0; j < red_objects; j = j + 1) {
                        center = get_object_center(RED, j);
                        area = get_object_area(RED, j);
                        printf("red    %3d %3d %5d\n", center.x, center.y, area);
                        if(is_correct_position(center) == TRUE) {
                            if (area >= RED_AREA) {
                                return TRUE;
                            }
                            else {
                                break;
                            }
                            msleep(100);
                        }
                    }*/
                }
                else {
                    break;
                }
            }
        }
    }
    return FALSE;
}

void right_tower() {
    servo(lift, lift_up_smaller_tower);
    backward_with_encoder(18, NORMAL_SPEED);
    spin_right_with_encoder(98, NORMAL_SPEED);
    forward_with_encoder(33, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(180, NORMAL_SPEED);
    servo(lift, lift_down);
    servo(claw, claw_open);
}

void middle_tower() {
    //change last lift_down to lowest other way
    enable_servos();
    servo(lift, lift_up);
    backward_with_encoder(6, NORMAL_SPEED);
    spin_right_with_encoder(98, NORMAL_SPEED);
    forward_with_encoder(32, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(200, NORMAL_SPEED);
    servo(lift, lift_down_other);
    servo(claw, claw_open);
    servo(lift, lift_up);
    //Right Tower
    spin_left_with_encoder(90, 90);
    forward_with_encoder(12, 90);
    spin_left_with_encoder(100, 90);
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(1, 90);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_left_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(3, NORMAL_SPEED);
    servo(lift, lift_down_other);
    servo(claw, claw_open);
    servo(lift, lift_down);
}

void left_tower(){
    enable_servos();
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(101, NORMAL_SPEED);
    forward_with_encoder(22, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(3, NORMAL_SPEED);
    servo(lift, lift_down_other);
    servo(claw, claw_open);
    servo(lift, lift_down);
}

void left_right() {
    //try switching the mayor and botguy
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(9, NORMAL_SPEED);
    spin_right_with_encoder(99, NORMAL_SPEED);
    forward_with_encoder(20, NORMAL_SPEED);
    servo(claw, claw_close);
    forward_with_encoder(0.25, NORMAL_SPEED);
    servo(claw, claw_open);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(8, NORMAL_SPEED);
    spin_right_with_encoder(148, NORMAL_SPEED);
    backward_with_encoder(2, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    //add printfs
    servo(lift, lift_down);
    middle_lwcu();
    //''
    TOGGLE = TRUE;
    backward_with_encoder(6, NORMAL_SPEED);
    spin_right_with_encoder(90, 90);
    forward_with_encoder(14, 90);
    spin_left_with_encoder(95, 90);
    backward_with_encoder(1, NORMAL_SPEED);
    servo(lift, lift_up_smaller_tower);
    servo(claw, claw_close);
    forward_with_encoder(0.25, NORMAL_SPEED);
    servo(claw, claw_open);
    servo(claw, claw_close);
    forward_with_encoder(0.25, NORMAL_SPEED);
    servo(lift, lift_up_smaller_tower_2);
    //forward_with_encoder(2, NORMAL_SPEED);
    backward_with_encoder(12, NORMAL_SPEED);
    spin_left_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(9, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_down);
    forward_with_encoder(6, 90);
}

void left_middle() {
    //TOGGLE=TRUE;
    //try switching the mayor and botguy
    enable_servos();
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(9, NORMAL_SPEED);
    spin_right_with_encoder(99, NORMAL_SPEED);
    forward_with_encoder(20, NORMAL_SPEED);
    servo(claw, claw_close);
    forward_with_encoder(1.5, NORMAL_SPEED);
    msleep(1000);
    servo(claw, claw_open);
    msleep(1000);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(8, NORMAL_SPEED);
    spin_right_with_encoder(145, NORMAL_SPEED);
    backward_with_encoder(2, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_up);
    spin_left_with_encoder(45, 90);
    forward_with_encoder(16, NORMAL_SPEED);
    spin_left_with_encoder(95, NORMAL_SPEED); //changed right to left
    forward_with_encoder(11, NORMAL_SPEED);
    servo(lift, lift_up_2);
    servo(claw, claw_close);
    forward_with_encoder(0.5, NORMAL_SPEED);
    msleep(1000);
    servo(claw, claw_open);
    msleep(1000);
    servo(claw, claw_close);
    msleep(1000);
    servo(lift, lift_up);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(200, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    msleep(5000);
    /*servo(lift, lift_up_smaller_tower);
    forward_with_encoder(14, NORMAL_SPEED);
    spin_right_with_encoder(101, NORMAL_SPEED);
    forward_with_encoder(22.5, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10.5, NORMAL_SPEED);
    spin_right_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(3, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_up);
    spin_left_with_encoder(48, NORMAL_SPEED);
    forward_with_encoder(16, NORMAL_SPEED);
    spin_left_with_encoder(90, NORMAL_SPEED); //changed right to left
    forward_with_encoder(14, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(200, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_up);
    servo(lift, lift_down);*/
}

void middle_right() {
    //TOGGLE=TRUE;
    enable_servos();
    left_lwcu();
    backward_with_encoder(6, NORMAL_SPEED);
    spin_right_with_encoder(90, NORMAL_SPEED);
    forward_with_encoder(12, NORMAL_SPEED);
    servo(lift, lift_up);
    spin_left_with_encoder(90, NORMAL_SPEED);
    forward_with_encoder(16, NORMAL_SPEED);
    servo(claw, claw_close);
    forward_with_encoder(0.5, NORMAL_SPEED);
    msleep(1000);
    servo(claw, claw_open);
    msleep(1000);
    servo(claw, claw_close);
    msleep(1000);
    servo(lift, lift_up_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(200, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_up_smaller_tower);
    spin_left_with_encoder(90, NORMAL_SPEED);
    forward_with_encoder(14, NORMAL_SPEED);
    spin_left_with_encoder(100, NORMAL_SPEED);
    forward_with_encoder(2, NORMAL_SPEED);
    servo(lift, lift_up_smaller_tower);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_left_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(3, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_down);
}

void all_towers() {
    enable_servos();
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(9.5, NORMAL_SPEED);
    spin_right_with_encoder(98, NORMAL_SPEED);
    forward_with_encoder(22.5, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(12, NORMAL_SPEED);
    spin_right_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(2.5, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_up);
    spin_left_with_encoder(48, NORMAL_SPEED);
    forward_with_encoder(16, NORMAL_SPEED);
    spin_left_with_encoder(85, NORMAL_SPEED); //changed right to left
    forward_with_encoder(10.5, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_2);
    msleep(1000);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(200, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    msleep(5000);
    servo(lift, lift_up);
    spin_left_with_encoder(90, NORMAL_SPEED);
    forward_with_encoder(14.5, NORMAL_SPEED);
    spin_left_with_encoder(105, NORMAL_SPEED);
    forward_with_encoder(0.5, NORMAL_SPEED);
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(1.5, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_left_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(7, NORMAL_SPEED);
    servo(lift, lift_down_3);
    forward_with_encoder(4, NORMAL_SPEED);
    servo(claw, claw_open);
    servo(lift, lift_down);

    spin_right_with_encoder(43, NORMAL_SPEED);
    forward_with_encoder(18, NORMAL_SPEED);
    spin_right_with_encoder(5, NORMAL_SPEED);
}

void left_lwcu() {
    forward_with_encoder(9, NORMAL_SPEED);
    spin_left_with_encoder(5, NORMAL_SPEED);
    servo(lift, 1875);
    msleep(1000);
    servo(claw, claw_open);
    msleep(1000);
    servo(claw, claw_close);
    msleep(1000);
    servo(lift, lift_up_smaller_tower_lwcu);
    msleep(1000);
    spin_right_with_encoder(110, NORMAL_SPEED);
    forward_with_encoder(20, NORMAL_SPEED);
    servo(claw, claw_open);
}

void middle_lwcu() {
    spin_right_with_encoder(100, NORMAL_SPEED);
    forward_with_encoder(4, NORMAL_SPEED);
    msleep(1000);
    servo(claw, claw_open);
    servo(lift, 1875);
    servo(claw, claw_close);
    servo(lift, lift_up);
    backward_with_encoder(4, NORMAL_SPEED);
    spin_left_with_encoder(148, NORMAL_SPEED);
    forward_with_encoder(12, NORMAL_SPEED);
    spin_left_with_encoder(90, NORMAL_SPEED);
    forward_with_encoder(14, NORMAL_SPEED);
    servo(claw, claw_open);
}

void right_lwcu() {
    servo(lift, lift_up);
    spin_right_with_encoder(50, NORMAL_SPEED);
    forward_with_encoder(18, NORMAL_SPEED);
    spin_left_with_encoder(90, NORMAL_SPEED);
    servo(claw, claw_open);
    servo(lift, 1875);
    servo(claw, claw_close);
    spin_left_with_encoder(90, NORMAL_SPEED);
    forward_with_encoder(6, NORMAL_SPEED);
    spin_left_with_encoder(90, NORMAL_SPEED);
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(20, NORMAL_SPEED);
    servo(claw, claw_open);
}

void find_fire(tries, pictures) {
    take_pictures(pictures);
    if(is_on_fire(tries) == TRUE) {
        printf("left_right\n");
        left_right();
    }
    else {
        spin_right_with_encoder(15, NORMAL_SPEED);
        take_pictures(pictures);
        if(is_on_fire(tries) == TRUE) {
            printf("left_middle\n");
            spin_left_with_encoder(15, NORMAL_SPEED);
            left_middle();
        }
        else {
            spin_left_with_encoder(15, NORMAL_SPEED);
            printf("middle_right\n");
            middle_right();
        }
    }
}
