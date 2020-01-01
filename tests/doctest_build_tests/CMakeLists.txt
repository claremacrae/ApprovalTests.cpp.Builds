set(PROGRAM_NAME doctest_build_tests)
add_executable(${PROGRAM_NAME}
        main.cpp
        DoctestBasicApprovalTest.cpp
        )
target_link_libraries(doctest_build_tests PRIVATE ApprovalTests doctest::doctest)
add_test(NAME ${PROGRAM_NAME} COMMAND ${PROGRAM_NAME})
