//
// Created by smile on 2022/1/5.
//

#include <gtest/gtest.h>
#include <vector>
#include "super-pow.cpp"

namespace {
    TEST(superPowTest, Example1) {      // NOLINT
        int a = 2;
        std::vector<int> b = {3};
        auto ans = Solution::superPow(a, b);
        decltype(ans) correctAns = 8;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(superPowTest, Example2) {      // NOLINT
        int a = 2;
        std::vector<int> b = {1, 0};
        auto ans = Solution::superPow(a, b);
        decltype(ans) correctAns = 1024;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(superPowTest, Example3) {      // NOLINT
        int a = 1;
        std::vector<int> b = {4, 3, 3, 8, 2, 5};
        auto ans = Solution::superPow(a, b);
        decltype(ans) correctAns = 1;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}