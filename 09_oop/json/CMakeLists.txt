cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
project(09json)

set(CMAKE_CXX_STANDARD 17)

add_executable(09json Json.h test_json.cpp)