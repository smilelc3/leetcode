//
// Created by smile on 2021/4/12.
//
#include <gtest/gtest.h>
#include <vector>
#include "binary-tree-level-order-traversal-ii.cpp"

namespace {
    TEST(levelOrderBottomTest, Example1) {
        auto root = GenTreeByNums(std::vector<int>{3, 9, 20, -1, -1, 15, 7}, -1);
        auto ans = (new Solution)->levelOrderBottom(root);
        std::vector<std::vector<int>> rightAns = {{15, 7},
                                                  {9,  20},
                                                  {3}};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(levelOrderBottomTest, Example2) {
        auto root = GenTreeByNums(std::vector<int>{1});
        auto ans = (new Solution)->levelOrderBottom(root);
        std::vector<std::vector<int>> rightAns = {{1}};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(levelOrderBottomTest, Example3) {
        auto root = GenTreeByNums(std::vector<int>{});
        auto ans = (new Solution)->levelOrderBottom(root);
        std::vector<std::vector<int>> rightAns = {};
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
