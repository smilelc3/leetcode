//
// Created by smile on 2021/6/6.
//

#include <gtest/gtest.h>
#include "maximum-product-subarray.cpp"

namespace {
    TEST(maxProductTest, Example1) {        // NOLINT
        std::vector<int> nums = {2, 3, -2, 4};
        auto ans = Solution().maxProduct(nums);
        decltype(ans) rightAns = 6;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(maxProductTest, Example2) {        // NOLINT
        std::vector<int> nums = {-2, 0, -1};
        auto ans = Solution().maxProduct(nums);
        decltype(ans) rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(maxProductTest, MyTest0) {        // NOLINT
        std::vector<int> nums = {-2, 3, -2, 4, 1, 3, -100, 0};
        auto ans = Solution().maxProduct(nums);
        decltype(ans) rightAns = 7200;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
