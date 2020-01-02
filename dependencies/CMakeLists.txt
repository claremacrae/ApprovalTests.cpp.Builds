include(FetchContent)

# https://cliutils.gitlab.io/modern-cmake/chapters/projects/fetch.html
# TODO  Fix this on github actions ubuntu-latest
#       See https://github.com/claremacrae/ApprovalTests.cpp.Builds/runs/370228537
#            CMake Error at dependencies/CMakeLists.txt:9 (add_subdirectory):
#              add_subdirectory called with incorrect number of arguments
#            Call Stack (most recent call first):
#              dependencies/CMakeLists.txt:32 (FetchContent_MakeAvailable)
#
#            CMake Error at dependencies/CMakeLists.txt:9 (add_subdirectory):
#              add_subdirectory called with incorrect number of arguments
#            Call Stack (most recent call first):
#              dependencies/CMakeLists.txt:33 (FetchContent_MakeAvailable)
#
#if(${CMAKE_VERSION} VERSION_LESS 3.14)
#    macro(FetchContent_MakeAvailable NAME)
#        FetchContent_GetProperties(${NAME})
#        if(NOT ${NAME}_POPULATED)
#            FetchContent_Populate(${NAME})
#            add_subdirectory(${${NAME}_SOURCE_DIR} ${${NAME}_BINARY_DIR})
#        endif()
#    endmacro()
#endif()

# TODO Move version numbers to top-level CMake file, and make them controllable options
# TODO Add option as to whether to include each of these
# TODO Add option as to whether to load the tests in each of these - currently working on this in tests/CMakeLists.txt
# TODO Add other ApprovalTests projects

FetchContent_Declare(ApprovalTests
                     GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
                     GIT_TAG fead5802b291c6e40ac8be9dfaf8372b9187862d)

FetchContent_Declare(Catch2
                     GIT_REPOSITORY https://github.com/catchorg/Catch2.git
                     GIT_TAG v2.11.1)

FetchContent_Declare(doctest
                     GIT_REPOSITORY https://github.com/onqtam/doctest.git
                     GIT_TAG 2.3.6)

FetchContent_Declare(googletest
                     GIT_REPOSITORY https://github.com/abseil/googletest.git
                     GIT_TAG release-1.8.1)

FetchContent_Declare(ut
                     GIT_REPOSITORY https://github.com/boost-experimental/ut.git
                     GIT_TAG 8004290d195b08eda531eb015ddcda2e11d41ce9)

FetchContent_MakeAvailable(ApprovalTests)
FetchContent_MakeAvailable(Catch2)
FetchContent_MakeAvailable(doctest)
FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(ut)
