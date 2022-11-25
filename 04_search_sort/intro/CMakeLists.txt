cmake_minimum_required(VERSION 3.1...3.24)
project(findanumber
        VERSION 1.0
        LANGUAGES CXX)
add_executable(findanumber binsearch.cpp, linsearch.cpp)