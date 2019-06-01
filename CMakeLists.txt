cmake_minimum_required(VERSION 3.14)
project(hello_world)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-lncurses")

add_executable(hello_world hello_world.cpp)
add_executable(initialization initialization.cpp)