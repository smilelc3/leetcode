//
// Created by smile on 2021/4/13.
//

#include <gtest/gtest.h>
#include <TreeNode.h>
#include "diameter-of-binary-tree.h"

namespace {
    TEST(diameterOfBinaryTreeTest, Example1) {       // NOLINT
        auto root = TreeCreateByNums({1, 2, 3, 4, 5});
        auto ans = Solution().diameterOfBinaryTree(root);
        decltype(ans) correctAns = 3;
        ASSERT_EQ(ans, correctAns);
        TreeDestroy(root);
    }

    TEST(diameterOfBinaryTreeTest, Example2) {       // NOLINT
        auto root = TreeCreateByNums({1, 2});
        auto ans = Solution().diameterOfBinaryTree(root);
        decltype(ans) correctAns = 1;
        ASSERT_EQ(ans, correctAns);
        TreeDestroy(root);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
