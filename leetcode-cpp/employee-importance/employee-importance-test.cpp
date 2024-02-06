//
// Created by smile on 2024/2/6.
//

#include <gtest/gtest.h>
#include <TreeNode.h>
#include "employee-importance.cpp"

namespace {
    TEST(getImportanceTest, Example1) {       // NOLINT
        auto employee1 = Employee{1, 5, {2, 3}};
        auto employee2 = Employee{2, 3, {}};
        auto employee3 = Employee{3, 3, {}};
        auto ans = Solution::getImportance({&employee1, &employee2, &employee3}, 1);
        decltype(ans) correctAns = 11;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(getImportanceTest, Example2) {       // NOLINT
        auto employee1 = Employee{1, 2, {5}};
        auto employee2 = Employee{5, -3, {}};
        auto ans = Solution::getImportance({&employee1, &employee2}, 5);
        decltype(ans) correctAns = -3;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
