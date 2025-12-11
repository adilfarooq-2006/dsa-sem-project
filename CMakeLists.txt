cmake_minimum_required(VERSION 3.10)
project(dsa_sem_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dsa_sem_project
        main.cpp
        Ahmed_Data.cpp
        FloodSystem.h "City.h" "InventorySystem.h" "PriorityQueueSystem.h" "Ehsaan_Work.cpp")
