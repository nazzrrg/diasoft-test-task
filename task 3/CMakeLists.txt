cmake_minimum_required(VERSION 3.20)
project(prog2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lcurl")

add_executable(prog2 prog2.cpp)
target_link_libraries(prog2 PRIVATE curl)