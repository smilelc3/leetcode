//
// Created by smile on 2021/4/29.
//

#include <gtest/gtest.h>
#include "binary-tree-postorder-traversal.cpp"

namespace {
    TEST(postorderTraversalTest, Example1) {
        auto root = GenTreeByNums({1, -1, 2, 3}, -1);
        auto ans = Solution().postorderTraversal(root);
        std::vector<int> rightAns = {3, 2, 1};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(postorderTraversalTest, Example2) {
        auto root = GenTreeByNums({});
        auto ans = Solution().postorderTraversal(root);
        std::vector<int> rightAns{};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(postorderTraversalTest, Example3) {
        auto root = GenTreeByNums({1});
        auto ans = Solution().postorderTraversal(root);
        std::vector<int> rightAns = {1};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(postorderTraversalTest, Example4) {
        auto root = GenTreeByNums({1,2});
        auto ans = Solution().postorderTraversal(root);
        std::vector<int> rightAns = {2,1};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(postorderTraversalTest, Example5) {
        auto root = GenTreeByNums({1,-1,2},-1);
        auto ans = Solution().postorderTraversal(root);
        std::vector<int> rightAns = {2,1};
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}