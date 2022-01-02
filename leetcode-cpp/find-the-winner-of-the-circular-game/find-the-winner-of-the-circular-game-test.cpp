//
// Created by smile on 2022/1/1.
//

#include <gtest/gtest.h>
#include "find-the-winner-of-the-circular-game.cpp"

namespace {
    TEST(findTheWinnerTest, Example1) {   // NOLINT
        auto n = 5, k = 2;
        auto ans = Solution::findTheWinner(n, k);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(findTheWinnerTest, Example2) {   // NOLINT
        auto n = 6, k = 5;
        auto ans = Solution::findTheWinner(n, k);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(findTheWinnerTest, Test0) {   // NOLINT
        auto n = 3, k = 1;
        auto ans = Solution::findTheWinner(n, k);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}