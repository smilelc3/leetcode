#include <gtest/gtest.h>
#include <vector>
#include "path-sum.cpp"

namespace {
    TEST(hasPathSumTest, Example1) {
        auto nums = std::vector<int>{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, -1, 1};
        TreeNode *root = GenTreeByNums(nums, -1);
        int targetSum = 22;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_TRUE(ans);
    }


    TEST(hasPathSumTest, Example2) {
        auto nums = std::vector<int>{1, 2, 3};
        TreeNode *root = GenTreeByNums(nums, -1);
        int targetSum = 5;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
    }

    TEST(hasPathSumTest, Example3) {
        auto nums = std::vector<int>{1, 2};
        TreeNode *root = GenTreeByNums(nums, -1);
        int targetSum = 0;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
    }

    TEST(hasPathSumTest, nullTree) {
        std::vector<int> nums;
        TreeNode *root = GenTreeByNums(nums, -1);
        int targetSum = 0;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
    }

    TEST(hasPathSumTest, Test0) {
        auto nums = std::vector<int>{1, 2};
        TreeNode *root = GenTreeByNums(nums, -1);
        int targetSum = 1;
        bool ans = Solution::hasPathSum(root, targetSum);
        ASSERT_FALSE(ans);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
