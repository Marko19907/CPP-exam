cmake_minimum_required(VERSION 3.21)

project(exam_2022h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra -Wno-unused-parameter")


add_executable(task_1 src/task_1.cpp)
add_executable(task_2 src/task_2.cpp)
add_executable(task_3 src/task_3.cpp)
add_executable(task_4 src/task_4.cpp)
