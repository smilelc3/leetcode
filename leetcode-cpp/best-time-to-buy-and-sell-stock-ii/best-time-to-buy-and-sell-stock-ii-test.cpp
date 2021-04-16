//
// Created by smile on 2021/4/16.
//


#include <gtest/gtest.h>
#include <vector>
#include "best-time-to-buy-and-sell-stock-ii.cpp"

namespace {
    TEST(maxProfitTest, Example1) {
        auto prices = std::vector<int>{7, 1, 5, 3, 6, 4};
        int ans = (new Solution)->maxProfit(prices);
        int rightAns = 5;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(maxProfitTest, Example2) {
        auto prices = std::vector<int>{7, 1, 5, 3, 6, 4};
        int ans = (new Solution)->maxProfit(prices);
        int rightAns = 5;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}