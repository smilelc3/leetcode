//
// Created by l30014168 on 2022/3/22.
//


#include <gtest/gtest.h>
#include "find-the-duplicate-number.cpp"

namespace {
    TEST(findDuplicateTest, Example1) {   // NOLINT
        std::vector<int> nums = {1, 3, 4, 2, 2};
        auto ans = Solution::findDuplicate(nums);
        decltype(ans) rightAns = 2;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(findDuplicateTest, Example2) {   // NOLINT
        std::vector<int> nums = {3, 1, 3, 4, 2};
        auto ans = Solution::findDuplicate(nums);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}