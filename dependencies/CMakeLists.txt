include(FetchContent)

FetchContent_Declare(ApprovalTests
                     GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
                     GIT_TAG 16dafceb580c87f140d869f37a2576539051a964)

FetchContent_Declare(Catch2
                     GIT_REPOSITORY https://github.com/catchorg/Catch2.git
                     GIT_TAG v2.11.1
        )

FetchContent_Declare(doctest
                     GIT_REPOSITORY https://github.com/onqtam/doctest.git
                     GIT_TAG 2.3.6
        )

FetchContent_MakeAvailable(ApprovalTests Catch2 doctest)
