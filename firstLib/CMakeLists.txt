cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

project(firstLib)

add_library(firstLib src/lib.cpp)
include_directories(include)