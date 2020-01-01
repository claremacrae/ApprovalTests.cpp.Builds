# FetchContent requires 3.11
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(ApprovalTests.cpp.Builds)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "The version of C++ to support (11, 14, 17, 20)")
set(CMAKE_CXX_STANDARD_REQUIRED yes CACHE STRING "")

add_subdirectory(dependencies)
add_subdirectory(tests)
