#include <gtest/gtest.h>
#include <vector>
#include "minimum-depth-of-binary-tree.cpp"

namespace {
    TEST(minDepthTest, Example1) {
        auto nums = std::vector<int>{3, 9, 20, -1, -1, 15, 7};
        TreeNode *root = GenTreeByNums(nums, -1);
        auto sol = Solution();
        int ans = sol.minDepth(root);
        int rightAns = 2;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
