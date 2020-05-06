cmake_minimum_required(VERSION 3.15)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c camera.c camera.h drive_systems.c drive_systems.h sensors.c sensors.h servors&motors.c servors&motors.h utilities.c utilities.h variables.h)