//
// Created by smile on 2021/6/18.
//

#include <gtest/gtest.h>
#include "binary-tree-right-side-view.cpp"

namespace {
    const int null = -1;
    TEST(rightSideViewTest, Example1) {     // NOLINT
        auto root = BinaryTree::createByNums({1, 2, 3, null, 5, -1, 4}, null);
        auto ans = Solution().rightSideView(root);
        decltype(ans) rightAns = {1, 3, 4};
        ASSERT_EQ(ans, rightAns);
        BinaryTree::destroy(root);
    }

    TEST(rightSideViewTest, Example2) {     // NOLINT
        auto root = BinaryTree::createByNums({1, null, 3}, null);
        auto ans = Solution().rightSideView(root);
        decltype(ans) rightAns = {1, 3};
        ASSERT_EQ(ans, rightAns);
        BinaryTree::destroy(root);
    }

    TEST(rightSideViewTest, Example3) {     // NOLINT
        auto root = BinaryTree::createByNums({});
        auto ans = Solution().rightSideView(root);
        decltype(ans) rightAns = {};
        ASSERT_EQ(ans, rightAns);
        BinaryTree::destroy(root);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}