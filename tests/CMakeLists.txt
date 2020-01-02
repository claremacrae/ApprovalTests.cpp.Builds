if (APPROVAL_TESTS_BUILDS_USE_CATCH2)
    add_subdirectory(catch2_build_tests)

    # Add ApprovalTests Catch2 tests
    add_subdirectory(
            "${CMAKE_BINARY_DIR}/_deps/approvaltests-src/tests/Catch2_Tests"
            "${CMAKE_BINARY_DIR}/_deps/approvaltests-build/tests/Catch2_Tests"
    )
endif(APPROVAL_TESTS_BUILDS_USE_CATCH2)

if (APPROVAL_TESTS_BUILDS_USE_DOCTEST)
    add_subdirectory(doctest_build_tests)

    # Add ApprovalTests doctest tests
    add_subdirectory(
            "${CMAKE_BINARY_DIR}/_deps/approvaltests-src/tests/DocTest_Tests"
            "${CMAKE_BINARY_DIR}/_deps/approvaltests-build/tests/DocTest_Tests"
    )
endif(APPROVAL_TESTS_BUILDS_USE_DOCTEST)

if (APPROVAL_TESTS_BUILDS_USE_GOOGLE_TEST)
    add_subdirectory(googletest_build_tests)

    # Add ApprovalTests googletest tests
    add_subdirectory(
            "${CMAKE_BINARY_DIR}/_deps/approvaltests-src/tests/GoogleTest_Tests"
            "${CMAKE_BINARY_DIR}/_deps/approvaltests-build/tests/GoogleTest_Tests"
    )
endif(APPROVAL_TESTS_BUILDS_USE_GOOGLE_TEST)

if (APPROVAL_TESTS_BUILDS_USE_BOOST_UT)
    add_subdirectory(ut_build_tests)

    # Add ApprovalTests Boost.ut tests
    add_subdirectory(
            "${CMAKE_BINARY_DIR}/_deps/approvaltests-src/tests/UT_Tests"
            "${CMAKE_BINARY_DIR}/_deps/approvaltests-build/tests/UT_Tests"
    )
endif(APPROVAL_TESTS_BUILDS_USE_BOOST_UT)
