cmake_minimum_required(VERSION 4.0)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkedList main.c
        LinkedList.h
        LinkedList.c)
