//
// Created by smile on 2021/4/29.
//

#include <gtest/gtest.h>
#include "binary-tree-postorder-traversal.cpp"

namespace {
    TEST(postorderTraversalTest, Example1) {        // NOLINT
        auto root = TreeCreateByNums({1, -1, 2, 3}, -1);
        auto ans = Solution().postorderTraversal(root);
        std::vector<int> rightAns = {3, 2, 1};
        ASSERT_EQ(ans, rightAns);
        TreeDestroy(root);

    }

    TEST(postorderTraversalTest, Example2) {        // NOLINT
        auto root = TreeCreateByNums({});
        auto ans = Solution().postorderTraversal(root);
        std::vector<int> rightAns{};
        ASSERT_EQ(ans, rightAns);
        TreeDestroy(root);
    }

    TEST(postorderTraversalTest, Example3) {        // NOLINT
        auto root = TreeCreateByNums({1});
        auto ans = Solution().postorderTraversal(root);
        std::vector<int> rightAns = {1};
        ASSERT_EQ(ans, rightAns);
        TreeDestroy(root);
    }

    TEST(postorderTraversalTest, Example4) {        // NOLINT
        auto root = TreeCreateByNums({1, 2});
        auto ans = Solution().postorderTraversal(root);
        std::vector<int> rightAns = {2, 1};
        ASSERT_EQ(ans, rightAns);
        TreeDestroy(root);
    }

    TEST(postorderTraversalTest, Example5) {        // NOLINT
        auto root = TreeCreateByNums({1, -1, 2}, -1);
        auto ans = Solution().postorderTraversal(root);
        std::vector<int> rightAns = {2, 1};
        ASSERT_EQ(ans, rightAns);
        TreeDestroy(root);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}