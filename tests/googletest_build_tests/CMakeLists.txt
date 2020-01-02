set(PROGRAM_NAME googletest_build_tests)
add_executable(${PROGRAM_NAME}
        main.cpp
        GoogleTestBasicApprovalTest.cpp
        )
target_link_libraries(${PROGRAM_NAME} PRIVATE ApprovalTests gtest gtest_main)
add_test(NAME ${PROGRAM_NAME} COMMAND ${PROGRAM_NAME})
