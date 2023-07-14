//
// Created by smile on 2023/7/14.
//

#include <gtest/gtest.h>
#include "min-cost-climbing-stairs.cpp"

namespace {
    TEST(minCostClimbingStairsTest, Example1) {        // NOLINT
        std::vector<int> cost = {10, 15, 20};
        auto ans = Solution::minCostClimbingStairs(cost);
        decltype(ans) correctAns = 15;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(minCostClimbingStairsTest, Example2) {        // NOLINT
        std::vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        auto ans = Solution::minCostClimbingStairs(cost);
        decltype(ans) correctAns = 6;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
