cmake_minimum_required(VERSION 3.25)
project(matamHW2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(matamHW2
        dry/main.cpp
        dry/Pirate.cpp
        dry/Pirate.h
        wet/Matrix.h wet/Matrix.cpp wet/MataMvidia.h wet/MataMvidia.cpp wet/tests.cpp)
