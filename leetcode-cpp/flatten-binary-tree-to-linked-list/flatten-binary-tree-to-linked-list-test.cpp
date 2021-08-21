#include <gtest/gtest.h>
#include "flatten-binary-tree-to-linked-list.cpp"

namespace {
    TEST(flattenTest, Example1) {       // NOLINT
        auto root = TreeCreateByNums({1, 2, 5, 3, 4, -1, 6}, -1);
        Solution().flatten(root);
        auto rightAns = TreeCreateByNums({1, -1, 2, -1, 3, -1, 4, -1, 5, -1, 6}, -1);
        EXPECT_TRUE(isSameTree(root, rightAns));
        TreeDestroy(root);
        TreeDestroy(rightAns);
    }

    TEST(flattenTest, Example2) {       // NOLINT
        auto root = TreeCreateByNums({});
        Solution().flatten(root);
        auto rightAns = TreeCreateByNums({});
        EXPECT_TRUE(isSameTree(root, rightAns));
        TreeDestroy(root);
        TreeDestroy(rightAns);
    }

    TEST(flattenTest, Example3) {       // NOLINT
        auto root = TreeCreateByNums({0});
        Solution().flatten(root);
        auto rightAns = TreeCreateByNums({0});
        EXPECT_TRUE(isSameTree(root, rightAns));
        TreeDestroy(root);
        TreeDestroy(rightAns);
    }

    TEST(flattenTest, Test0) {      // NOLINT
        auto root = TreeCreateByNums({1, 2, 5, 3, 4, -1, 6}, -1);
        Solution().flatten(root);
        auto rightAns = TreeCreateByNums({1, -1, 2, -1, 3, -1, 4, -1, 5, -1, 6}, -1);
        EXPECT_TRUE(isSameTree(root, rightAns));
        TreeDestroy(root);
        TreeDestroy(rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
