#include "gtest/gtest.h"
#include "ApprovalTests/Approvals.h"

TEST(GoogleTestBasicApprovalTest, ItCanVerify)
{
    ApprovalTests::Approvals::verify("Hello World");
}
