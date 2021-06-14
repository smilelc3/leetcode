//
// Created by smile on 2021/6/14.
//

#include <gtest/gtest.h>
#include "number-of-islands.cpp"

namespace {
    TEST(numIslandsTest, Example1) {     // NOLINT
        std::vector<std::vector<char>> grid = {
                {'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}
        };
        auto ans = Solution().numIslands(grid);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(numIslandsTest, Example2) {     // NOLINT
        std::vector<std::vector<char>> grid = {
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}
        };
        auto ans = Solution().numIslands(grid);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
