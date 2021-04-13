#include <gtest/gtest.h>
#include <vector>
#include "flatten-binary-tree-to-linked-list.cpp"

namespace {
    TEST(flattenTest, Example1) {
        auto root = GenTreeByNums({1, 2, 5, 3, 4, -1, 6}, -1);
        (new Solution)->flatten(root);
        auto rightAns = GenTreeByNums({1, -1, 2, -1, 3, -1, 4, -1, 5, -1, 6}, -1);
        EXPECT_TRUE(isSameTree(root, rightAns));
    }


    TEST(flattenTest, Example2) {
        auto root = GenTreeByNums({});
        (new Solution)->flatten(root);
        auto rightAns = GenTreeByNums({});
        EXPECT_TRUE(isSameTree(root, rightAns));
    }

    TEST(flattenTest, Example3) {
        auto root = GenTreeByNums({0});
        (new Solution)->flatten(root);
        auto rightAns = GenTreeByNums({0});
        EXPECT_TRUE(isSameTree(root, rightAns));
    }

    TEST(flattenTest, Test0) {
        auto root = GenTreeByNums({1, 2, 5, 3, 4, -1, 6}, -1);
        (new Solution)->flatten(root);
        auto rightAns = GenTreeByNums({1, -1, 2, -1, 3, -1, 4, -1, 5, -1, 6}, -1);
        EXPECT_TRUE(isSameTree(root, rightAns));
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
