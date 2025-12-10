cmake_minimum_required(VERSION 4.0)
project(dsa_sem_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dsa_sem_project
        main.cpp
        Ahmed_Data.cpp
        FloodSystem.h)
