//
// Created by smile on 2022/4/6.
//

#include <gtest/gtest.h>
#include "move-zeroes.cpp"

namespace {
    TEST(moveZeroesTest, Example1) {    // NOLINT
        std::vector<int> nums = {0, 1, 0, 3, 12};
        Solution::moveZeroes(nums);
        decltype(nums) rightAns = {1, 3, 12, 0, 0};
        ASSERT_EQ(nums, rightAns);
    }

    TEST(moveZeroesTest, Example2) {    // NOLINT
        std::vector<int> nums = {0};
        Solution::moveZeroes(nums);
        decltype(nums) rightAns = {0};
        ASSERT_EQ(nums, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
