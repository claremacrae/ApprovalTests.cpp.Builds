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
# TODO Add ApprovalTests.cpp.StarterProject
# TODO Add ApprovalTests.cpp.Qt
# TODO Add ApprovalTests.cpp.Qt.StarterProject
# TODO Add ApprovalTests.cpp.Demos
# TODO Add tests of accessing libraries via find_package()
#      See https://www.reddit.com/r/cmake/comments/a7d3gw/question_add_subdirectory_vs_find_package_vs/
# TODO Add tests of accessing libraries installed in the system
# TODO Add tests for when 3rd-pary libraries have already been pulled in, and are not needed
# TODO Add tests of Ninja generator (and others?)
# TODO Add tests of latest versions of all dependencies

FetchContent_Declare(ApprovalTests
        GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
        GIT_TAG fead5802b291c6e40ac8be9dfaf8372b9187862d)
FetchContent_MakeAvailable(ApprovalTests)

if (APPROVAL_TESTS_BUILDS_USE_CATCH2)
    # 2.3.0 is oldest supported, as of 2020-01-05
    FetchContent_Declare(Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v2.3.0)
    FetchContent_MakeAvailable(Catch2)
endif(APPROVAL_TESTS_BUILDS_USE_CATCH2)

if (APPROVAL_TESTS_BUILDS_USE_DOCTEST)
    # 2.3.4 is oldest supported, as of 2020-01-05
    FetchContent_Declare(doctest
            GIT_REPOSITORY https://github.com/onqtam/doctest.git
            GIT_TAG 2.3.4)
    FetchContent_MakeAvailable(doctest)
endif(APPROVAL_TESTS_BUILDS_USE_DOCTEST)

if (APPROVAL_TESTS_BUILDS_USE_GOOGLE_TEST)
    # Prevent GoogleTest from overriding our compiler/linker options
    # when building with Visual Studio
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_Declare(googletest
            GIT_REPOSITORY https://github.com/abseil/googletest.git
            GIT_TAG release-1.8.1)
    FetchContent_MakeAvailable(googletest)
endif(APPROVAL_TESTS_BUILDS_USE_GOOGLE_TEST)

if (APPROVAL_TESTS_BUILDS_USE_BOOST_UT)
    # TODO Add a Boost.UT issue asking for option names to have a prefix added
    set(BUILD_BENCHMARKS OFF)
    set(BUILD_EXAMPLES OFF)
    set(BUILD_TESTS OFF)
    FetchContent_Declare(ut
            GIT_REPOSITORY https://github.com/boost-experimental/ut.git
            GIT_TAG 8004290d195b08eda531eb015ddcda2e11d41ce9)
    FetchContent_MakeAvailable(ut)
endif(APPROVAL_TESTS_BUILDS_USE_BOOST_UT)
