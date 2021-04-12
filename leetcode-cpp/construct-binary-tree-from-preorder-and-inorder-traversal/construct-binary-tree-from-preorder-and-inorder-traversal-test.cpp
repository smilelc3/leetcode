//
// Created by smile on 2021/4/12.
//

#include <gtest/gtest.h>
#include <vector>
#include "construct-binary-tree-from-preorder-and-inorder-traversal.cpp"

namespace {
    TEST(buildTreeTest, Example1) {
        std::vector<int> preorder = {3, 9, 20, 15, 7};
        std::vector<int> inorder = {9, 3, 15, 20, 7};
        auto sol = new Solution();
        auto ans = sol->buildTree(preorder, inorder);
        auto rightAns = GenTreeByNums(std::vector<int>{3, 9, 20, -1, -1, 15, 7}, -1);
        ASSERT_TRUE(isSameTree(ans, rightAns));
    }

    TEST(buildTreeTest, Example2) {
        std::vector<int> preorder = {-1};
        std::vector<int> inorder = {-1};
        auto sol = new Solution();
        auto ans = sol->buildTree(preorder, inorder);
        auto rightAns = GenTreeByNums(std::vector<int>{-1}, 0);
        ASSERT_TRUE(isSameTree(ans, rightAns));
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
