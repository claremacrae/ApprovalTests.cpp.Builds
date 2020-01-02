# FetchContent requires 3.11
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(ApprovalTests.cpp.Builds)

option(APPROVAL_TESTS_BUILDS_USE_CATCH2 "Download, build and test integration with Catch2" ON)
option(APPROVAL_TESTS_BUILDS_USE_DOCTEST "Download, build and test integration with doctest" ON)
option(APPROVAL_TESTS_BUILDS_USE_GOOGLE_TEST "Download, build and test integration with Google Test" ON)

message("CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}")
if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION GREATER_EQUAL 9.2) OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION GREATER_EQUAL 9.0))
    option(APPROVAL_TESTS_BUILDS_USE_BOOST_UT "Download, build and test integration with Boost.UT" ON)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND CMAKE_CXX_SIMULATE_ID MATCHES "MSVC")
    # Does not currently build with clang-cl
    # See https://github.com/boost-experimental/ut/issues/277
    MESSAGE("[Boost].UT breaks compiler args for clang-cl, therefore it's disabled")
    set(APPROVAL_TESTS_BUILDS_USE_BOOST_UT OFF)
else()
    MESSAGE("The [Boost].UT integration with Approval Tests requires source_location support by the compiler, therefore it's disabled")
    set(APPROVAL_TESTS_BUILDS_USE_BOOST_UT OFF)
endif()

# Hack to prevent CTest-added targets from cluttering up CLion's list of targets
# See https://stackoverflow.com/questions/44949354/hide-automatically-generated-ctest-targets
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
enable_testing()

set(CMAKE_VERBOSE_MAKEFILE off)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "The version of C++ to support (11, 14, 17, 20)")
set(CMAKE_CXX_STANDARD_REQUIRED yes CACHE STRING "")

add_subdirectory(dependencies)
add_subdirectory(tests)
