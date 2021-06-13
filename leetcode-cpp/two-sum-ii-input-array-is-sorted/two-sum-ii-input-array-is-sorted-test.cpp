//
// Created by smile on 2021/6/13.
//


#include <gtest/gtest.h>
#include "two-sum-ii-input-array-is-sorted.cpp"

namespace {
    TEST(twoSumTest, Example1) {      // NOLINT
        std::vector<int> numbers = {2, 7, 11, 15};
        auto target = 9;
        auto ans = Solution().twoSum(numbers, target);
        decltype(ans) rightAns = {1, 2};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(twoSumTest, Example2) {      // NOLINT
        std::vector<int> numbers = {2, 3, 4};
        auto target = 6;
        auto ans = Solution().twoSum(numbers, target);
        decltype(ans) rightAns = {1, 3};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(twoSumTest, Example3) {      // NOLINT
        std::vector<int> numbers = {-1, 0};
        auto target = -1;
        auto ans = Solution().twoSum(numbers, target);
        decltype(ans) rightAns = {1, 2};
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
