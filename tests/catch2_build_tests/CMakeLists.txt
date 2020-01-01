set(PROGRAM_NAME catch2_build_tests)
add_executable(${PROGRAM_NAME}
        main.cpp
        Catch2BasicApprovalTest.cpp
        )
target_link_libraries(${PROGRAM_NAME} PRIVATE ApprovalTests Catch2::Catch2)
if (TARGET Catch2::Catch2Main)
    # link Catch2::Catch2Main only if it exists (so probably catch2 v3)
    target_link_libraries(${PROGRAM_NAME} PRIVATE Catch2::Catch2Main)
endif()
add_test(NAME ${PROGRAM_NAME} COMMAND ${PROGRAM_NAME})
