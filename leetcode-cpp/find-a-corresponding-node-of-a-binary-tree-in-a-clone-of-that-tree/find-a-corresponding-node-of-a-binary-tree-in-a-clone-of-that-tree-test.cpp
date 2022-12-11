//
// Created by smile on 2021/11/29.
//

#include <gtest/gtest.h>
#include "TreeNode.h"
#include "find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree.cpp"

const auto null = std::numeric_limits<int>::max();

namespace {
    TEST(getTargetCopyTest, Example1) {        // NOLINT
        auto original = BinaryTree::createByNums({7, 4, 3, null, null, 6, 19}, null);
        auto cloned = BinaryTree::createByNums({7, 4, 3, null, null, 6, 19}, null);
        auto target = original->right;
        auto ans = Solution().getTargetCopy(original, cloned, target);
        ASSERT_EQ(ans->val, target->val);
        ASSERT_NE(ans, target);
        BinaryTree::destroy(original);
        BinaryTree::destroy(cloned);
    }

    TEST(getTargetCopyTest, Example2) {        // NOLINT
        auto original = BinaryTree::createByNums({7});
        auto cloned = BinaryTree::createByNums({7});
        auto target = original;
        auto ans = Solution().getTargetCopy(original, cloned, target);
        ASSERT_EQ(ans->val, target->val);
        ASSERT_NE(ans, target);
        BinaryTree::destroy(original);
        BinaryTree::destroy(cloned);
    }

    TEST(getTargetCopyTest, Example3) {        // NOLINT
        auto original = BinaryTree::createByNums({8, null, 6, null, 5, null, 4, null, 3, null, 2, null, 1}, null);
        auto cloned = BinaryTree::createByNums({8, null, 6, null, 5, null, 4, null, 3, null, 2, null, 1}, null);
        auto target = original->right->right->right;
        auto ans = Solution().getTargetCopy(original, cloned, target);
        ASSERT_EQ(ans->val, target->val);
        ASSERT_NE(ans, target);
        BinaryTree::destroy(original);
        BinaryTree::destroy(cloned);
    }

    TEST(getTargetCopyTest, Example4) {        // NOLINT
        auto original = BinaryTree::createByNums({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        auto cloned = BinaryTree::createByNums({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        auto target = original->left->right;
        auto ans = Solution().getTargetCopy(original, cloned, target);
        ASSERT_EQ(ans->val, target->val);
        ASSERT_NE(ans, target);
        BinaryTree::destroy(original);
        BinaryTree::destroy(cloned);
    }

    TEST(getTargetCopyTest, Example5) {        // NOLINT
        auto original = BinaryTree::createByNums({1, 2, null, 3}, null);
        auto cloned = BinaryTree::createByNums({1, 2, null, 3}, null);
        auto target = original->left;
        auto ans = Solution().getTargetCopy(original, cloned, target);
        ASSERT_EQ(ans->val, target->val);
        ASSERT_NE(ans, target);
        BinaryTree::destroy(original);
        BinaryTree::destroy(cloned);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}