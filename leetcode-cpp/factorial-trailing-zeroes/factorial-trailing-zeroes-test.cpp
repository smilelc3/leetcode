//
// Created by smile on 2021/6/20.
//

#include <gtest/gtest.h>
#include "factorial-trailing-zeroes.cpp"

namespace {
    TEST(convertToTitleTest, Example1) {        // NOLINT
        int n = 3;
        auto ans = Solution().trailingZeroes(n);
        decltype(ans) rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(convertToTitleTest, Example2) {        // NOLINT
        int n = 5;
        auto ans = Solution().trailingZeroes(n);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(convertToTitleTest, Example3) {        // NOLINT
        int n = 0;
        auto ans = Solution().trailingZeroes(n);
        decltype(ans) rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}