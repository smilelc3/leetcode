//
// Created by smile on 2022/2/11.
//
#include <gtest/gtest.h>
#include "kth-largest-element-in-an-array.cpp"

namespace {
    TEST(findKthLargestTest, Example1) {      // NOLINT
        std::vector<int> nums = {3, 2, 1, 5, 6, 4};
        int k = 2;
        auto ans = Solution::findKthLargest(nums, k);
        decltype(ans) correctAns = 5;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(findKthLargestTest, Example2) {      // NOLINT
        std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        int k = 4;
        auto ans = Solution::findKthLargest(nums, k);
        decltype(ans) correctAns = 4;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
