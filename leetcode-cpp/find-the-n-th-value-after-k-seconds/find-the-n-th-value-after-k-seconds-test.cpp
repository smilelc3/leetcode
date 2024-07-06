//
// Created by smile on 2024/7/6.
//


#include <gtest/gtest.h>
#include "find-the-n-th-value-after-k-seconds.cpp"

namespace {
    TEST(valueAfterKSecondsTest, Example1) {   // NOLINT
        int n = 4, k = 5;
        auto ans = Solution::valueAfterKSeconds(n, k);
        decltype(ans) rightAns = 56;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(valueAfterKSecondsTest, Example2) {   // NOLINT
        int n = 5, k = 3;
        auto ans = Solution::valueAfterKSeconds(n, k);
        decltype(ans) rightAns = 35;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}