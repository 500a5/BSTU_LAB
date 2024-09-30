cmake_minimum_required(VERSION 3.13)
project(Blog)

set(CMAKE_CXX_STANDARD 11)

add_executable(Blog main.cpp listM.hpp Blog.h Blog.cpp User.h User.cpp Commentaire.cpp Commentaire.h Record.h Record.cpp)