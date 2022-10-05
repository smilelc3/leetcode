//
// Created by smile on 2022/10/5.
//

#include <gtest/gtest.h>
#include "nth-digit.cpp"

namespace {
    TEST(hfindNthDigitTest, Example1) {     // NOLINT
        int n = 3;
        auto ans = Solution().findNthDigit(n);
        decltype(ans) correctAns = 3;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(hfindNthDigitTest, Example2) {     // NOLINT
        int n = 11;
        auto ans = Solution().findNthDigit(n);
        decltype(ans) correctAns = 0;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(hfindNthDigitTest, Test0) {     // NOLINT
        int n = 1000000000;
        auto ans = Solution().findNthDigit(n);
        decltype(ans) correctAns = 1;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
