//
// Created by Becky on 3/16/2020.
//
#include <stdio.h>

#include "camera.h"
#include "variables.h"

//This file includes functions used for the camera

void picture_analyzing() {
    int p;
    printf("# of channels: %d\n", get_channel_count());
    for (p = 0; p <= 20; p += 1) {
        printf("Taking a picture... \n");

        camera_update();
        msleep(100);
    }
    printf("Channel 0's # of objects: %d\n", get_object_count(0));
    printf("Channel 0's largest object's area: %d\n", get_object_area(0, 0));
    printf("Channel 1's # of objects: %d\n", get_object_count(1));
    printf("Channel 1's largest object's area: %d\n", get_object_area(1, 0));
    printf("Channel 2's # of objects: %d\n", get_object_count(2));
    printf("Channel 2's largest object's area: %d\n", get_object_area(2, 0));
    printf("Channel 3's # of objects: %d\n", get_object_count(3));
    printf("Channel 3's largest object's area: %d\n", get_object_area(3, 0));
}

