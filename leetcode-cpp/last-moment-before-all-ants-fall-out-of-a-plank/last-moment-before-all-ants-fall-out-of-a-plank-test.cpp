//
// Created by smile on 2022/1/25.
//

#include <gtest/gtest.h>
#include "last-moment-before-all-ants-fall-out-of-a-plank.cpp"

namespace {
    TEST(getLastMomentTest, Example1) {      // NOLINT
        int n = 4;
        std::vector<int> left = {4, 3}, right = {0, 1};
        auto ans = Solution::getLastMoment(n, left, right);
        decltype(ans) correctAns = 4;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(getLastMomentTest, Example2) {      // NOLINT
        int n = 7;
        std::vector<int> left = {}, right = {0, 1, 2, 3, 4, 5, 6, 7};
        auto ans = Solution::getLastMoment(n, left, right);
        decltype(ans) correctAns = 7;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(getLastMomentTest, Example3) {      // NOLINT
        int n = 7;
        std::vector<int> left = {0, 1, 2, 3, 4, 5, 6, 7}, right = {};
        auto ans = Solution::getLastMoment(n, left, right);
        decltype(ans) correctAns = 7;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
