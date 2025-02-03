//
// Created by smile on 2025/2/3.
//

#include <gtest/gtest.h>
#include "average-of-levels-in-binary-tree.cpp"

namespace {
    const int null = -1;
    TEST(averageOfLevelsTest, Example1) {        // NOLINT
        auto root = BinaryTree::createByNums({3, 9, 20, null, null, 15, 7}, null);
        auto ans = Solution::averageOfLevels(root);
        decltype(ans) correctAns = {3.00000, 14.50000, 11.00000};
        ASSERT_EQ(ans, correctAns);
        BinaryTree::destroy(root);
    }
    
    TEST(averageOfLevelsTest, Example2) {        // NOLINT
        auto root = BinaryTree::createByNums({3, 9, 20, 15, 7});
        auto ans = Solution::averageOfLevels(root);
        decltype(ans) correctAns = {3.00000, 14.50000, 11.00000};
        ASSERT_EQ(ans, correctAns);
        BinaryTree::destroy(root);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
