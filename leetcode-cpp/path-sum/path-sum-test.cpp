#include <gtest/gtest.h>
#include <vector>
#include "path-sum.cpp"

namespace {
    TEST(hasPathSumTest, Example1) {
        TreeNode *root = GenTreeByNums({5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, -1, 1}, -1);
        int targetSum = 22;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_TRUE(ans);
    }


    TEST(hasPathSumTest, Example2) {
        TreeNode *root = GenTreeByNums({1, 2, 3}, -1);
        int targetSum = 5;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
    }

    TEST(hasPathSumTest, Example3) {
        TreeNode *root = GenTreeByNums({1, 2}, -1);
        int targetSum = 0;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
    }

    TEST(hasPathSumTest, nullTree) {
        TreeNode *root = GenTreeByNums({}, -1);
        int targetSum = 0;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
    }

    TEST(hasPathSumTest, Test0) {
        TreeNode *root = GenTreeByNums({1, 2}, -1);
        int targetSum = 1;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
