cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
project(08student)

set(CMAKE_CXX_STANDARD 17)

include(doctest.cmake)
add_executable(08student test_student.cpp doctest.h Student.cpp Student.h StudentList.cpp StudentList.h)
target_link_libraries(08student PRIVATE doctest)
