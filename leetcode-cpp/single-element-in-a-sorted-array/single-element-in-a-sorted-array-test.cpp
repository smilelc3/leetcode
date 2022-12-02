//
// Created by smile on 2022/12/2.
//


#include <gtest/gtest.h>
#include "single-element-in-a-sorted-array.cpp"

namespace {
    TEST(singleNonDuplicateTest, Example1) {      // NOLINT
        std::vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
        auto ans = Solution::singleNonDuplicate(nums);
        decltype(ans) correctAns = 2;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(singleNonDuplicateTest, Example2) {      // NOLINT
        std::vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
        auto ans = Solution::singleNonDuplicate(nums);
        decltype(ans) correctAns = 10;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
