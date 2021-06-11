//
// Created by smile on 2021/6/11.
//

#include <gtest/gtest.h>
#include "find-peak-element.cpp"

namespace {
    TEST(findPeakElementTest, Example1) {   // NOLINT
        std::vector<int> nums = {1, 2, 3, 1};
        auto ans = Solution().findPeakElement(nums);
        auto rightAns = 2;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(findPeakElementTest, Example2) {   // NOLINT
        std::vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
        auto ans = Solution().findPeakElement(nums);
        auto rightAns0 = 5, rightAns1 = 2;
        ASSERT_TRUE(ans == rightAns0 or ans == rightAns1);
    }

    TEST(findPeakElementTest, Test0) {   // NOLINT
        std::vector<int> nums = {1, 2};
        auto ans = Solution().findPeakElement(nums);
        auto rightAns = 1;
        ASSERT_TRUE(ans == rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}