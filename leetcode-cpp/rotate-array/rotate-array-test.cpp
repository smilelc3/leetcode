//
// Created by smile on 2022/1/27.
//

#include <gtest/gtest.h>
#include "rotate-array.cpp"

namespace {
    TEST(rotateTest, Example1) {      // NOLINT
        std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;
        Solution().rotate(nums, k);
        decltype(nums) correctAns = {5, 6, 7, 1, 2, 3, 4};
        ASSERT_EQ(nums, correctAns);
    }

    TEST(rotateTest, Example2) {      // NOLINT
        std::vector<int> nums = {-1, -100, 3, 99};
        int k = 2;
        Solution().rotate(nums, k);
        decltype(nums) correctAns = {3, 99, -1, -100};
        ASSERT_EQ(nums, correctAns);
    }

    TEST(rotateTest, Test0) {      // NOLINT
        std::vector<int> nums = {1, 2};
        int k = 0;
        Solution().rotate(nums, k);
        decltype(nums) correctAns = {1, 2};
        ASSERT_EQ(nums, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
