cmake_minimum_required(VERSION 3.26)
project(morsin_time)

set(CMAKE_CXX_STANDARD 14)

add_executable(morsin_time
        main.cpp
        includes/Oscillator.cpp
        includes/consts.h
        includes/metadata.cpp
        includes/characters.cpp
        includes/txt2morse.cpp)
