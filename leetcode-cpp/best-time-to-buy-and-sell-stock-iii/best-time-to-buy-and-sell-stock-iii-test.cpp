//
// Created by smile on 2021/5/18.
//

#include <gtest/gtest.h>
#include "best-time-to-buy-and-sell-stock-iii.cpp"

namespace {
    TEST(maxProfitTest, Example1) { // NOLINT
        auto prices = std::vector<int>{3, 3, 5, 0, 0, 3, 1, 4};
        auto ans = Solution().maxProfit(prices);
        decltype(ans) rightAns = 6;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(maxProfitTest, Example2) { // NOLINT
        auto prices = std::vector<int>{1, 2, 3, 4, 5};
        auto ans = Solution().maxProfit(prices);
        decltype(ans) rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(maxProfitTest, Example3) { // NOLINT
        auto prices = std::vector<int>{7, 6, 4, 3, 1};
        auto ans = Solution().maxProfit(prices);
        decltype(ans) rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(maxProfitTest, Example4) { // NOLINT
        auto prices = std::vector<int>{1};
        auto ans = Solution().maxProfit(prices);
        decltype(ans) rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}