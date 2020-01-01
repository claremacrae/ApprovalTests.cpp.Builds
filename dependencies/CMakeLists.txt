include(FetchContent)

# TODO Move version numbers to top-level CMake file, and make them controllable options
# TODO Add GTest
# TODO Add option as to whether to include each of these
# TODO Add option as to whether to load the tests in each of these - currently working on this in tests/CMakeLists.txt
# TODO Add other ApprovalTests projects

FetchContent_Declare(ApprovalTests
                     GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
                     GIT_TAG 7cbba407a15dcc96cf94232fdf5939a77e6a7057)

FetchContent_Declare(Catch2
                     GIT_REPOSITORY https://github.com/catchorg/Catch2.git
                     GIT_TAG v2.11.1)

FetchContent_Declare(doctest
                     GIT_REPOSITORY https://github.com/onqtam/doctest.git
                     GIT_TAG 2.3.6)

FetchContent_MakeAvailable(ApprovalTests Catch2 doctest)
