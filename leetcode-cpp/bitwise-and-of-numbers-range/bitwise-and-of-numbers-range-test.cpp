//
// Created by smile on 2022/1/28.
//
#include <gtest/gtest.h>
#include "bitwise-and-of-numbers-range.cpp"

namespace {
    TEST(rangeBitwiseAndTest, Example1) {     // NOLINT
        int left = 5, right = 7;
        auto ans = Solution().rangeBitwiseAnd(left, right);
        decltype(ans) rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(rangeBitwiseAndTest, Example2) {     // NOLINT
        int left = 0, right = 0;
        auto ans = Solution().rangeBitwiseAnd(left, right);
        decltype(ans) rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(rangeBitwiseAndTest, Example3) {     // NOLINT
        int left = 1, right = 2147483647;
        auto ans = Solution().rangeBitwiseAnd(left, right);
        decltype(ans) rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(rangeBitwiseAndTest, Test0) {     // NOLINT
        int left = 1, right = 1;
        auto ans = Solution().rangeBitwiseAnd(left, right);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(rangeBitwiseAndTest, Test1) {     // NOLINT
        int left = 5, right = 5;
        auto ans = Solution().rangeBitwiseAnd(left, right);
        decltype(ans) rightAns = 5;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}