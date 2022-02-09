//
// Created by smile on 2021/6/15.
//

#include <gtest/gtest.h>
#include "house-robber.cpp"

namespace {
    TEST(robTest, Example1) {      // NOLINT
        std::vector<int> nums = {1, 2, 3, 1};
        auto ans = Solution().rob(nums);
        decltype(ans) rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(robTest, Example2) {      // NOLINT
        std::vector<int> nums = {2, 7, 9, 3, 1};
        auto ans = Solution().rob(nums);
        decltype(ans) rightAns = 12;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
