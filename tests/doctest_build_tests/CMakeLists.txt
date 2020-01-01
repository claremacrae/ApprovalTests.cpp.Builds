add_executable(doctest_build_tests
        main.cpp
        DoctestBasicApprovalTest.cpp
        )
target_link_libraries(doctest_build_tests PRIVATE ApprovalTests doctest::doctest)
