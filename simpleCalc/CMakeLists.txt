cmake_minimum_required(VERSION 3.12)

project(simpleCalc)

set(CMAKE_CXX_STANDARD 17)

add_executable(simpleCalc src/main.cpp)
add_library(simpleCalcLib src/calc.cpp)
include_directories(include)

target_link_libraries(simpleCalc simpleCalcLib)
