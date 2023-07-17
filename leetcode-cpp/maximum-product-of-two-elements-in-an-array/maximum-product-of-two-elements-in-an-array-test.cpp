//
// Created by smile on 2023/7/17.
//

#include <gtest/gtest.h>
#include "maximum-product-of-two-elements-in-an-array.cpp"

namespace {
    TEST(maxProductTest, Example1) {        // NOLINT
        auto ans = Solution::maxProduct({3, 4, 5, 2});
        decltype(ans) correctAns = 12;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(maxProductTest, Example2) {        // NOLINT
        auto ans = Solution::maxProduct({1, 5, 4, 5});
        decltype(ans) correctAns = 16;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(maxProductTest, Example3) {        // NOLINT
        auto ans = Solution::maxProduct({3, 7});
        decltype(ans) correctAns = 12;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
