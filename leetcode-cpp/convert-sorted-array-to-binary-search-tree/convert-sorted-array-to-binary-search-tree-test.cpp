//
// Created by smile on 2021/4/12.
//

#include <gtest/gtest.h>
#include <vector>
#include "convert-sorted-array-to-binary-search-tree.cpp"

namespace {
    TEST(sortedArrayToBSTTest, Example1) {      // NOLINT
        std::vector<int> nums = {-10, -3, 0, 5, 9};
        auto ans = Solution().sortedArrayToBST(nums);
        auto rightAns1 = TreeCreateByNums({0, -3, 9, -10, -1, 5}, -1);
        auto rightAns2 = TreeCreateByNums({0, -10, 5, -1, -3, -1, 9}, -1);
        ASSERT_TRUE(isSameTree(ans, rightAns1) or isSameTree(ans, rightAns2));
        TreeDestroy(ans);
        TreeDestroy(rightAns1);
        TreeDestroy(rightAns2);
    }

    TEST(sortedArrayToBSTTest, Example2) {      // NOLINT
        std::vector<int> nums = {1, 3};
        auto ans = Solution().sortedArrayToBST(nums);
        auto rightAns1 = TreeCreateByNums({3, 1});
        auto rightAns2 = TreeCreateByNums({1, -1, 3}, -1);
        ASSERT_TRUE(isSameTree(ans, rightAns1) or isSameTree(ans, rightAns2));
        TreeDestroy(ans);
        TreeDestroy(rightAns1);
        TreeDestroy(rightAns2);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

