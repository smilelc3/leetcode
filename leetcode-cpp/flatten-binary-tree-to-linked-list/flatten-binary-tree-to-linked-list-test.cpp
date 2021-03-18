#include <gtest/gtest.h>
#include <vector>
#include "flatten-binary-tree-to-linked-list.cpp"

namespace {
    TEST(flattenTest, Example1) {
        auto nums = std::vector<int>{1, 2, 5, 3, 4, -1, 6};
        auto root = GenTreeByNums(nums, -1);
        auto sol = Solution();
        sol.flatten(root);
        std::vector<int> rightAnsNums = {1, -1, 2, -1, 3, -1, 4, -1, 5, -1, 6};
        auto rightAns = GenTreeByNums(rightAnsNums, -1);
        EXPECT_TRUE(isSameTree(root, rightAns));
    }


    TEST(flattenTest, Example2) {
        auto nums = std::vector<int>{};
        auto root = GenTreeByNums(nums, -1);
        auto sol = Solution();
        sol.flatten(root);
        std::vector<int> rightAnsNums = {};
        auto rightAns = GenTreeByNums(rightAnsNums, -1);
        EXPECT_TRUE(isSameTree(root, rightAns));
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
