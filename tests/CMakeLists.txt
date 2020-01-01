add_subdirectory(catch2_build_tests)
add_subdirectory(doctest_build_tests)

# ------------------------------------------------------------------------------
# Add ApprovalTests tests...

# Add ApprovalTests Catch2 tests

add_subdirectory(
        "${CMAKE_BINARY_DIR}/_deps/approvaltests-src/tests/Catch2_Tests"
        "${CMAKE_BINARY_DIR}/_deps/approvaltests-build/tests/Catch2_Tests"
)

# TODO Add ApprovalTests doctest tests
# TODO Add ApprovalTests googletest tests
# TODO Add ApprovalTests Boost.ut tests
