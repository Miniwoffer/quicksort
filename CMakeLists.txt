cmake_minimum_required(VERSION 3.6)
project(quicksort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Quicksort_main.cpp)

add_executable(quicksort ${SOURCE_FILES})