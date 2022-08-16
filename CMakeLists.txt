cmake_minimum_required(VERSION 3.23)
project(homework3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(homework3
        list.cpp
        list.h
        main.cpp
        main.h
        word.cpp
        word.h)
