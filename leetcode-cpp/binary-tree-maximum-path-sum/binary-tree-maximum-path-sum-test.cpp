//
// Created by smile on 2021/4/28.
//

#include <gtest/gtest.h>
#include <vector>
#include "binary-tree-maximum-path-sum.cpp"

namespace {
    TEST(maxPathSumTest, Example1) {        // NOLINT
        auto root = BinaryTree::createByNums({1, 2, 3});
        auto ans = Solution().maxPathSum(root);
        auto rightAns = 6;
        ASSERT_EQ(ans, rightAns);
        BinaryTree::destroy(root);
    }

    const int null = -1;
    TEST(maxPathSumTest, Example2) {        // NOLINT
        auto root = BinaryTree::createByNums({-10, 9, 20, null, null, 15, 7}, null);
        auto ans = Solution().maxPathSum(root);
        auto rightAns = 42;
        ASSERT_EQ(ans, rightAns);
        BinaryTree::destroy(root);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
