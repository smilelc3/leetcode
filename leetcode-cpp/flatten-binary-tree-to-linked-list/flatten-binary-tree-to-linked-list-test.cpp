#include <gtest/gtest.h>
#include "flatten-binary-tree-to-linked-list.cpp"

namespace {
    TEST(flattenTest, Example1) {       // NOLINT
        auto root = BinaryTree::createByNums({1, 2, 5, 3, 4, -1, 6}, -1);
        Solution().flatten(root);
        auto rightAns = BinaryTree::createByNums({1, -1, 2, -1, 3, -1, 4, -1, 5, -1, 6}, -1);
        EXPECT_TRUE(BinaryTree::isEqual(root, rightAns));
        BinaryTree::destroy(root);
        BinaryTree::destroy(rightAns);
    }

    TEST(flattenTest, Example2) {       // NOLINT
        auto root = BinaryTree::createByNums({});
        Solution().flatten(root);
        auto rightAns = BinaryTree::createByNums({});
        EXPECT_TRUE(BinaryTree::isEqual(root, rightAns));
        BinaryTree::destroy(root);
        BinaryTree::destroy(rightAns);
    }

    TEST(flattenTest, Example3) {       // NOLINT
        auto root = BinaryTree::createByNums({0});
        Solution().flatten(root);
        auto rightAns = BinaryTree::createByNums({0});
        EXPECT_TRUE(BinaryTree::isEqual(root, rightAns));
        BinaryTree::destroy(root);
        BinaryTree::destroy(rightAns);
    }

    TEST(flattenTest, Test0) {      // NOLINT
        auto root = BinaryTree::createByNums({1, 2, 5, 3, 4, -1, 6}, -1);
        Solution().flatten(root);
        auto rightAns = BinaryTree::createByNums({1, -1, 2, -1, 3, -1, 4, -1, 5, -1, 6}, -1);
        EXPECT_TRUE(BinaryTree::isEqual(root, rightAns));
        BinaryTree::destroy(root);
        BinaryTree::destroy(rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
