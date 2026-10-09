cmake_minimum_required(VERSION 4.3)
project(UceniC C)

set(CMAKE_C_STANDARD 11)

add_executable(UceniC main.c
        array/arrayFunc.c
        array/array.h
        map/map.h
        map/mapFunc.c)
