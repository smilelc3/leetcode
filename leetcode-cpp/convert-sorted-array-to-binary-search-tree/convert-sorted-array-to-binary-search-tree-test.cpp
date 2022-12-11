//
// Created by smile on 2021/4/12.
//

#include <gtest/gtest.h>
#include <vector>
#include "convert-sorted-array-to-binary-search-tree.cpp"

namespace {
    const int null = -1;
    TEST(sortedArrayToBSTTest, Example1) {      // NOLINT
        std::vector<int> nums = {-10, -3, 0, 5, 9};
        auto ans = Solution().sortedArrayToBST(nums);
        auto rightAns1 = BinaryTree::createByNums({0, -3, 9, -10, null, 5}, null);
        auto rightAns2 = BinaryTree::createByNums({0, -10, 5, null, -3, null, 9}, null);
        ASSERT_TRUE(BinaryTree::isEqual(ans, rightAns1) or BinaryTree::isEqual(ans, rightAns2));
        BinaryTree::destroy(ans);
        BinaryTree::destroy(rightAns1);
        BinaryTree::destroy(rightAns2);
    }

    TEST(sortedArrayToBSTTest, Example2) {      // NOLINT
        std::vector<int> nums = {1, 3};
        auto ans = Solution().sortedArrayToBST(nums);
        auto rightAns1 = BinaryTree::createByNums({3, 1});
        auto rightAns2 = BinaryTree::createByNums({1, null, 3}, null);
        ASSERT_TRUE(BinaryTree::isEqual(ans, rightAns1) or BinaryTree::isEqual(ans, rightAns2));
        BinaryTree::destroy(ans);
        BinaryTree::destroy(rightAns1);
        BinaryTree::destroy(rightAns2);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

