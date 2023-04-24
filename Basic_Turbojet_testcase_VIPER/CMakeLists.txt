cmake_minimum_required(VERSION 3.21)
project(Test_cases)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test_cases main.cpp inlet.cpp inlet.h compressor.cpp compressor.h turbine.cpp turbine.h nozzle.cpp nozzle.h)
