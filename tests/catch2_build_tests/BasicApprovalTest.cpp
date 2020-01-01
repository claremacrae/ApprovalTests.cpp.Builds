#include <catch2/catch.hpp>
#include "ApprovalTests/Approvals.h"
TEST_CASE("It Can Verify")
{
    ApprovalTests::Approvals::verify("Hello World");
}
