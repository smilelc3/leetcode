//
// Created by smile on 2023/9/8.
//

#include <gtest/gtest.h>
#include "diagonal-traverse-ii.cpp"

namespace {
    TEST(findDiagonalOrderTest, Example1) {        // NOLINT
        std::vector<std::vector<int>> nums = {{1, 2, 3},
                                              {4, 5, 6},
                                              {7, 8, 9}};
        auto ans = Solution::findDiagonalOrder(nums);
        decltype(ans) correctAns = {1, 4, 2, 7, 5, 3, 8, 6, 9};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(findDiagonalOrderTest, Example2) {        // NOLINT
        std::vector<std::vector<int>> nums = {{1,  2,  3,  4,  5},
                                              {6,  7},
                                              {8},
                                              {9,  10, 11},
                                              {12, 13, 14, 15, 16}};
        auto ans = Solution::findDiagonalOrder(nums);
        decltype(ans) correctAns = {1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(findDiagonalOrderTest, Test0) {        // NOLINT
    std::vector<std::vector<int>> nums = {{14, 12, 19, 16, 9},
                                          {13, 14, 15, 8,  11},
                                          {11, 13, 1}};
    auto ans = Solution::findDiagonalOrder(nums);
    decltype(ans) correctAns = {14, 13, 12, 11, 14, 19, 13, 15, 16, 1, 8, 9, 11};
    ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}