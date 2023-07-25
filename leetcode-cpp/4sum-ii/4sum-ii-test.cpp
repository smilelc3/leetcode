//
// Created by smile on 2023/6/6.
//

#include <gtest/gtest.h>
#include "4sum-ii.cpp"

namespace {
    TEST(fourSumCountTest, Example1) {     // NOLINT
        std::vector<int> nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};
        auto ans = Solution::fourSumCount(nums1, nums2, nums3, nums4);
        decltype(ans) correctAns = 2;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(fourSumCountTest, Example2) {     // NOLINT
        std::vector<int> nums1 = {0}, nums2 = {0}, nums3 = {0}, nums4 = {0};
        auto ans = Solution::fourSumCount(nums1, nums2, nums3, nums4);
        decltype(ans) correctAns = 1;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(fourSumCountTest, TEST0) {     // NOLINT
        std::vector<int> nums1 = {-1, -1}, nums2 = {-1, 1}, nums3 = {-1, 1}, nums4 = {1, -1};
        auto ans = Solution::fourSumCount(nums1, nums2, nums3, nums4);
        decltype(ans) correctAns = 6;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(fourSumCountTest, TEST1) {     // NOLINT
        std::vector<int> nums1 = {0, 1, -1}, nums2 = {-1, 1, 0}, nums3 = {0, 0, 1}, nums4 = {-1, 1, 1};
        auto ans = Solution::fourSumCount(nums1, nums2, nums3, nums4);
        decltype(ans) correctAns = 17;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}