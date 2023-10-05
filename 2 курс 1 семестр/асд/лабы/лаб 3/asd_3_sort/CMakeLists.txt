cmake_minimum_required(VERSION 3.14)
project(asd_3_sort C)

set(CMAKE_C_STANDARD 99)

add_executable(asd_3_sort main.c sort.c sort.h FIFO.c FIFO.h)