add_executable(catch2_build_tests
        main.cpp
        BasicApprovalTest.cpp
        )
target_link_libraries(catch2_build_tests PRIVATE ApprovalTests Catch2::Catch2)
if (TARGET Catch2::Catch2Main)
    # link Catch2::Catch2Main only if it exists (so probably catch2 v3)
    target_link_libraries(my-project-test PRIVATE Catch2::Catch2Main)
endif()
