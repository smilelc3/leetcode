#include <gtest/gtest.h>
#include <vector>
#include "balanced-binary-tree.cpp"

namespace {
    const int null = -1;
    TEST(isBalancedTest, Example1) {        // NOLINT
        auto root = BinaryTree::createByNums({3, 9, 20, null, null, 15, 7}, null);
        int result = Solution::isBalanced(root);
        ASSERT_TRUE(result);
        BinaryTree::destroy(root);
    }

    TEST(isBalanced, Example2) {            // NOLINT
        auto root = BinaryTree::createByNums({1, 2, 2, 3, 3, null, null, 4, 4}, null);
        int result = Solution::isBalanced(root);
        ASSERT_FALSE(result);
        BinaryTree::destroy(root);
    }

    TEST(isBalancedTest, nullTree) {        // NOLINT
        TreeNode *root = nullptr;
        int result = Solution::isBalanced(root);
        ASSERT_TRUE(result);
        BinaryTree::destroy(root);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
