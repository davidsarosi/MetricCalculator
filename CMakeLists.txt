cmake_minimum_required(VERSION 3.16)
project(untitled_histo)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled_histo main.cpp MetricCalculator.cpp MetricCalculator.h catch.hpp test.cpp)