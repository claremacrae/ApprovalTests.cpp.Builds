#include <doctest/doctest.h>
#include "ApprovalTests/Approvals.h"

TEST_CASE("It Can Verify")
{
    ApprovalTests::Approvals::verify("Hello World");
}
