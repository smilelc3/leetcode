//
// Created by smile on 2022/3/15.
//

#include <gtest/gtest.h>
#include "diagonal-traverse.cpp"

namespace {
    TEST(findDiagonalOrderTest, Example1) {        // NOLINT
        std::vector<std::vector<int>> mat = {{1, 2, 3},
                                             {4, 5, 6},
                                             {7, 8, 9}};
        auto ans = Solution::findDiagonalOrder(mat);
        decltype(ans) rightAns = {1, 2, 4, 7, 5, 3, 6, 8, 9};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(findDiagonalOrderTest, Example2) {        // NOLINT
        std::vector<std::vector<int>> mat = {{1, 2},
                                             {3, 4}};
        auto ans = Solution::findDiagonalOrder(mat);
        decltype(ans) rightAns = {1, 2, 3, 4};
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}