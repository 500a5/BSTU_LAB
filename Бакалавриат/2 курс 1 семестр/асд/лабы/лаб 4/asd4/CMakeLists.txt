cmake_minimum_required(VERSION 3.14)
project(asd4 C)

set(CMAKE_C_STANDARD 99)

add_executable(asd4 main.c Search.c Search.h table_array.c table_array.h FIFO_prior_array.c FIFO_prior_array.h)