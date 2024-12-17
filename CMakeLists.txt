cmake_minimum_required(VERSION 3.10)
project(hw13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(hw13 main.cpp "conversion.h" "conversion.cpp")