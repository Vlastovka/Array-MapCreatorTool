cmake_minimum_required(VERSION 4.3)
project(UceniC C)

set(CMAKE_C_STANDARD 11)

add_executable(UceniC main.c
        arrayFunc.c
        array.h)
