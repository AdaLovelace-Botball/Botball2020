//
// Created by Becky on 3/16/2020.
//
#include <stdio.h>

#include "sensors.h"
#include "variables.h"

//This file includes functions used for sensors (excluding the camera)

void line_following(int loops) { //uses tophat sensors to follow black lines via bumping
    int a;
    printf("Analog 0 value is %d\n", analog(0));
    while (a <= loops) { //each loop lasts around 1/50 of a second, or 20 milliseconds
        if (analog(1) < 2500 && analog(0) > 2500) { //bumps right
            printf("analog(1) < 2500 && analog(0) > 2500 \n");
            printf("Analog value 0 is %d\n", analog(0));
            printf("Analog value 1 is %d\n", analog(1));
            motor(0, 10);
            motor(1, 90);
        }
        if (analog(0) < 2500 && analog(1) > 2500) { //bumps left
            printf("analog(0) < 2500 && analog(1) > 2500 \n");
            printf("Analog value 0 is %d\n", analog(0));
            printf("Analog value 1 is %d\n", analog(1));
            motor(0, 90);
            motor(1, 10);
        }
        if (analog(0) > 2500 && analog(1) > 2500) { //does a strange turn specified for the pre-conference
            printf("analog(0) > 2500 && analog(1) > 2500 \n");
            printf("Analog value 0 is %d\n", analog(0));
            printf("Analog value 1 is %d\n", analog(1));
            motor(0, 60);
            motor(1, 0);
        }
        else { //goes forward
            printf("other \n");
            printf("Analog value 0 is %d\n", analog(0));
            printf("Analog value 1 is %d\n", analog(1));
            motor(0, 30);
            motor(1, 40);
        }
        msleep(20);
        a ++;
    }
}
