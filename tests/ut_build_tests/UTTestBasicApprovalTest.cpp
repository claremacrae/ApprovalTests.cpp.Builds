#define APPROVALS_UT
#include "ApprovalTests/integrations/ut/UTApprovals.h"
#include "ApprovalTests/Approvals.h"

int main()
{
    using namespace boost::ut;
    using namespace ApprovalTests;

    auto directory = Approvals::useApprovalsSubdirectory("approval_tests");

    "It Can Verify"_test = []() {
        ApprovalTests::Approvals::verify("Hello World");
    };
}
