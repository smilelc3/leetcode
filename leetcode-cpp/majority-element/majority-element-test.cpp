//
// Created by smile on 2021/6/14.
//

#include <gtest/gtest.h>
#include "majority-element.cpp"

namespace {
    TEST(maxProductTest, Example1) {        // NOLINT
        std::vector<int> nums = {3, 2, 3};
        auto ans = Solution().majorityElement(nums);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(maxProductTest, Example2) {        // NOLINT
        std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        auto ans = Solution().majorityElement(nums);
        decltype(ans) rightAns = 2;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
