//
// Created by smile on 2021/4/28.
//

#include <gtest/gtest.h>
#include <vector>
#include "binary-tree-maximum-path-sum.cpp"

namespace {
    TEST(maxPathSumTest, Example1) {
        auto root = GenTreeByNums(std::vector<int>{1, 2, 3});
        auto ans = (new Solution)->maxPathSum(root);
        auto rightAns = 6;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(maxPathSumTest, Example2) {
        auto root = GenTreeByNums(std::vector<int>{-10, 9, 20, -1, -1, 15, 7}, -1);
        auto ans = (new Solution)->maxPathSum(root);
        auto rightAns = 42;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
