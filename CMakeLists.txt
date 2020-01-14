# FetchContent requires 3.11
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(ApprovalTests.cpp.Builds)

option(APPROVAL_TESTS_BUILDS_USE_CATCH2 "Download, build and test integration with Catch2" ON)
option(APPROVAL_TESTS_BUILDS_USE_DOCTEST "Download, build and test integration with doctest" ON)
option(APPROVAL_TESTS_BUILDS_USE_GOOGLE_TEST "Download, build and test integration with Google Test" ON)

set(APPROVAL_TESTS_BUILDS_USE_APPROVAL_TESTS_CPP_GIT_TAG    master)

set(APPROVAL_TESTS_BUILDS_USE_CATCH                         OFF)
set(APPROVAL_TESTS_BUILDS_USE_CATCH2_GIT_TAG                v2.3.0)

set(APPROVAL_TESTS_BUILDS_USE_DOCTEST                       OFF)
set(APPROVAL_TESTS_BUILDS_USE_DOCTEST_GIT_TAG               2.3.4)

set(APPROVAL_TESTS_BUILDS_USE_GOOGLE_TEST                   OFF)
set(APPROVAL_TESTS_BUILDS_USE_GOOGLE_TEST_GIT_TAG           release-1.8.1)

set(APPROVAL_TESTS_BUILDS_USE_BOOST                         ON)
# Can't update to master at the moment https://github.com/boost-experimental/ut/issues/291
set(APPROVAL_TESTS_BUILDS_USE_BOOST_UT_GIT_TAG              ec49196855078d98738f54023b488b2f85299826)


message("CMake Version = ${CMAKE_VERSION}")
message("CMake Generator = ${CMAKE_GENERATOR}")
message("ApprovalTests.cpp = ${APPROVAL_TESTS_BUILDS_USE_APPROVAL_TESTS_CPP_GIT_TAG}")
message("Boost.ut = ${APPROVAL_TESTS_BUILDS_USE_BOOST_UT_GIT_TAG}")

message("CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}")
if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION GREATER_EQUAL 9.2) OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION GREATER_EQUAL 9.0))
    option(APPROVAL_TESTS_BUILDS_USE_BOOST_UT "Download, build and test integration with Boost.UT" ON)
else()
    MESSAGE("The [Boost].UT integration with Approval Tests requires source_location support by the compiler, therefore it's disabled")
    set(APPROVAL_TESTS_BUILDS_USE_BOOST_UT OFF)
endif()

if(APPROVAL_TESTS_BUILDS_USE_BOOST_UT)
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND CMAKE_CXX_SIMULATE_ID MATCHES "MSVC")
        # Does not currently build with clang-cl
        # See https://github.com/boost-experimental/ut/issues/277
        MESSAGE("[Boost].UT breaks compiler args for clang-cl, therefore it's disabled")
        set(APPROVAL_TESTS_BUILDS_USE_BOOST_UT OFF)
    endif()
endif(APPROVAL_TESTS_BUILDS_USE_BOOST_UT)

# Hack to prevent CTest-added targets from cluttering up CLion's list of targets
# See https://stackoverflow.com/questions/44949354/hide-automatically-generated-ctest-targets
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
enable_testing()

set(CMAKE_VERBOSE_MAKEFILE on)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "The version of C++ to support (11, 14, 17, 20)")
set(CMAKE_CXX_STANDARD_REQUIRED yes CACHE STRING "")

add_subdirectory(dependencies)
add_subdirectory(tests)
