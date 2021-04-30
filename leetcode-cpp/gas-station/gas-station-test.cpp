//
// Created by smile on 2021/4/29.
//

#include <gtest/gtest.h>
#include "gas-station.cpp"

namespace {
    TEST(canCompleteCircuitTest, Example1) {
        std::vector<int> gas = {1, 2, 3, 4, 5};
        std::vector<int> cost = {3, 4, 5, 1, 2};
        auto ans = Solution().canCompleteCircuit(gas, cost);
        decltype(ans) rightAns = 3;
        EXPECT_EQ(ans, rightAns);
    }

    TEST(canCompleteCircuitTest, Example2) {
        std::vector<int> gas = {2, 3, 4};
        std::vector<int> cost = {3, 4, 3};
        auto ans = Solution().canCompleteCircuit(gas, cost);
        decltype(ans) rightAns = -1;
        EXPECT_EQ(ans, rightAns);
    }

    TEST(canCompleteCircuitTest, Test0) {
        std::vector<int> gas = {3, 3, 4};
        std::vector<int> cost = {3, 4, 4};
        auto ans = Solution().canCompleteCircuit(gas, cost);
        decltype(ans) rightAns = -1;
        EXPECT_EQ(ans, rightAns);
    }

    TEST(canCompleteCircuitTest, Test1) {
        std::vector<int> gas = {1, 1, 3};
        std::vector<int> cost = {2, 2, 1};
        auto ans = Solution().canCompleteCircuit(gas, cost);
        decltype(ans) rightAns = 2;
        EXPECT_EQ(ans, rightAns);
    }

    TEST(canCompleteCircuitTest, Test2) {
        std::vector<int> gas = {5, 8, 2, 8};
        std::vector<int> cost = {6, 5, 6, 6};
        auto ans = Solution().canCompleteCircuit(gas, cost);
        decltype(ans) rightAns = 3;
        EXPECT_EQ(ans, rightAns);
    }

    TEST(canCompleteCircuitTest, Test3) {
        std::vector<int> gas = {3, 1, 1};
        std::vector<int> cost = {1, 2, 2};
        auto ans = Solution().canCompleteCircuit(gas, cost);
        decltype(ans) rightAns = 0;
        EXPECT_EQ(ans, rightAns);
    }

    TEST(canCompleteCircuitTest, Test4) {
        std::vector<int> gas = {5, 5, 1, 3, 4};
        std::vector<int> cost = {8, 1, 7, 1, 1};
        auto ans = Solution().canCompleteCircuit(gas, cost);
        decltype(ans) rightAns = 3;
        EXPECT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
