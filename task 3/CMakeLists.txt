cmake_minimum_required(VERSION 3.20)
project(task_3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lcurl")

add_executable(task_3 prog2.cpp)
target_link_libraries(task_3 curl)