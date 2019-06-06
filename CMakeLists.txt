cmake_minimum_required(VERSION 3.14)
project(hello_world)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-lncurses")

add_executable(hello_world hello_world.cpp)
add_executable(initialization initialization.cpp)
add_executable(io io.cpp)
add_executable(attributes attributes.cpp)
add_executable(windows windows.cpp)
add_executable(window_border window_border.cpp)
add_executable(colors colors.cpp)
add_executable(key_menu key_menu.cpp)