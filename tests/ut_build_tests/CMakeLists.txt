set(PROGRAM_NAME ut_build_tests)
set(CMAKE_CXX_STANDARD 20)
add_executable(${PROGRAM_NAME}
        UTTestBasicApprovalTest.cpp
        )
target_link_libraries(ut_build_tests PRIVATE ApprovalTests boost.ut)
add_test(NAME ${PROGRAM_NAME} COMMAND ${PROGRAM_NAME})
