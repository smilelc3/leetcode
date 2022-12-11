//
// Created by smile on 2021/4/12.
//

#include <gtest/gtest.h>
#include <vector>
#include "construct-binary-tree-from-inorder-and-postorder-traversal.cpp"

namespace {
    const int null = -1;
    TEST(buildTreeTest, Example1) {     // NOLINT
        std::vector<int> preorder = {9, 3, 15, 20, 7};
        std::vector<int> inorder = {9, 15, 7, 20, 3};
        auto ans = Solution().buildTree(preorder, inorder);
        auto rightAns = BinaryTree::createByNums({3, 9, 20, null, null, 15, 7}, null);
        ASSERT_TRUE(BinaryTree::isEqual(ans, rightAns));
        BinaryTree::destroy(ans);
        BinaryTree::destroy(rightAns);
    }

    TEST(buildTreeTest, Example2) {     // NOLINT
        std::vector<int> preorder = {-1};
        std::vector<int> inorder = {-1};
        auto ans = Solution().buildTree(preorder, inorder);
        auto rightAns = BinaryTree::createByNums({-1});
        ASSERT_TRUE(BinaryTree::isEqual(ans, rightAns));
        BinaryTree::destroy(ans);
        BinaryTree::destroy(rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
