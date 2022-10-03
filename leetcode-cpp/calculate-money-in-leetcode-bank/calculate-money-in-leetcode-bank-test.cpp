//
// Created by smile on 2022/10/3.
//

#include <gtest/gtest.h>
#include "calculate-money-in-leetcode-bank.cpp"

namespace {
    TEST(totalMoneyTest, Example1) {
        int n = 4;
        auto ans = Solution::totalMoney(n);
        auto correctAns = 10;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(totalMoneyTest, Example2) {
        int n = 10;
        auto ans = Solution::totalMoney(n);
        auto correctAns = 37;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(totalMoneyTest, Example3) {
        int n = 20;
        auto ans = Solution::totalMoney(n);
        auto correctAns = 96;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}