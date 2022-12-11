//
// Created by smile on 2021/4/12.
//
#include <gtest/gtest.h>
#include <vector>
#include "binary-tree-level-order-traversal-ii.cpp"

namespace {
    const int null = -1;
    TEST(levelOrderBottomTest, Example1) {      // NOLINT
        auto root = BinaryTree::createByNums({3, 9, 20, null, null, 15, 7}, null);
        auto ans = Solution().levelOrderBottom(root);
        std::vector<std::vector<int>> rightAns = {{15, 7},
                                                  {9,  20},
                                                  {3}};
        ASSERT_EQ(ans, rightAns);
        BinaryTree::destroy(root);
    }

    TEST(levelOrderBottomTest, Example2) {      // NOLINT
        auto root = BinaryTree::createByNums({1});
        auto ans = Solution().levelOrderBottom(root);
        std::vector<std::vector<int>> rightAns = {{1}};
        ASSERT_EQ(ans, rightAns);
        BinaryTree::destroy(root);
    }

    TEST(levelOrderBottomTest, Example3) {      // NOLINT
        auto root = BinaryTree::createByNums({});
        auto ans = Solution().levelOrderBottom(root);
        std::vector<std::vector<int>> rightAns = {};
        ASSERT_EQ(ans, rightAns);
        BinaryTree::destroy(root);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
