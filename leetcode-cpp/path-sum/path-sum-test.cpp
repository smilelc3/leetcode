#include <gtest/gtest.h>
#include <vector>
#include "path-sum.cpp"

namespace {
    TEST(hasPathSumTest, Example1) {        // NOLINT
        TreeNode *root = BinaryTree::createByNums({5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, -1, 1}, -1);
        int targetSum = 22;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_TRUE(ans);
        BinaryTree::destroy(root);
    }


    TEST(hasPathSumTest, Example2) {        // NOLINT
        TreeNode *root = BinaryTree::createByNums({1, 2, 3}, -1);
        int targetSum = 5;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
        BinaryTree::destroy(root);
    }

    TEST(hasPathSumTest, Example3) {        // NOLINT
        TreeNode *root = BinaryTree::createByNums({1, 2}, -1);
        int targetSum = 0;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
        BinaryTree::destroy(root);
    }

    TEST(hasPathSumTest, nullTree) {        // NOLINT
        TreeNode *root = BinaryTree::createByNums({}, -1);
        int targetSum = 0;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
        BinaryTree::destroy(root);
    }

    TEST(hasPathSumTest, Test0) {           // NOLINT
        TreeNode *root = BinaryTree::createByNums({1, 2}, -1);
        int targetSum = 1;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
        BinaryTree::destroy(root);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
