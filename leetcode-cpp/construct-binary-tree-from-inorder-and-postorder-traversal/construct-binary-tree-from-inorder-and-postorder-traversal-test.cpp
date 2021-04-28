//
// Created by smile on 2021/4/12.
//

#include <gtest/gtest.h>
#include <vector>
#include "construct-binary-tree-from-inorder-and-postorder-traversal.cpp"

namespace {
    TEST(buildTreeTest, Example1) {
        std::vector<int> preorder = {9, 3, 15, 20, 7};
        std::vector<int> inorder = {9, 15, 7, 20, 3};
        auto ans = Solution().buildTree(preorder, inorder);
        auto rightAns = GenTreeByNums({3, 9, 20, -1, -1, 15, 7}, -1);
        ASSERT_TRUE(isSameTree(ans, rightAns));
    }

    TEST(buildTreeTest, Example2) {
        std::vector<int> preorder = {-1};
        std::vector<int> inorder = {-1};
        auto ans = Solution().buildTree(preorder, inorder);
        auto rightAns = GenTreeByNums({-1});
        ASSERT_TRUE(isSameTree(ans, rightAns));
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
