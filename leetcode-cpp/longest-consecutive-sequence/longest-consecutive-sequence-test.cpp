//
// Created by smile on 2021/4/8.
//


#include <gtest/gtest.h>
#include <vector>
#include "longest-consecutive-sequence.cpp"

namespace {
    TEST(longestConsecutiveTest, Example1) {
        auto nums = std::vector<int>{100, 4, 200, 1, 3, 2};
        auto ans = Solution::longestConsecutive(nums);
        int rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }


    TEST(longestConsecutiveTest, Example2) {
        auto nums = std::vector<int>{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        auto ans = Solution::longestConsecutive(nums);
        int rightAns = 9;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(longestConsecutiveTest, NullNums) {
        auto nums = std::vector<int>{};
        auto ans = Solution::longestConsecutive(nums);
        int rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(longestConsecutiveTest, Test0) {
        auto nums = std::vector<int>{1, 2, 0, 1};
        auto ans = Solution::longestConsecutive(nums);
        int rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}