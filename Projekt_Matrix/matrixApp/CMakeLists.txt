cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD  17)

include_directories(../matrixLib/include)

add_executable(Projekt_Matrix main.cpp)

target_link_libraries(Projekt_Matrix Projekt_Matrix_Lib)