# FetchContent requires 3.11
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# Hack to prevent CTest-added targets from cluttering up CLion's list of targets
# See https://stackoverflow.com/questions/44949354/hide-automatically-generated-ctest-targets
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
enable_testing()

set(CMAKE_VERBOSE_MAKEFILE on)

project(ApprovalTests.cpp.Builds)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "The version of C++ to support (11, 14, 17, 20)")
set(CMAKE_CXX_STANDARD_REQUIRED yes CACHE STRING "")

add_subdirectory(dependencies)
add_subdirectory(tests)
