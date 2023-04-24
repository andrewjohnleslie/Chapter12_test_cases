cmake_minimum_required(VERSION 3.25)
project(Basic_Turbojet_testcase_VIPER_class)

set(CMAKE_CXX_STANDARD 14)

add_executable(Basic_Turbojet_testcase_VIPER_class main.cpp inlet.h compressor.h turbine.h nozzle.h)
