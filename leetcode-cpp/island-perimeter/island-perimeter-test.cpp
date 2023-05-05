//
// Created by smile on 2023/5/5.
//

#include <gtest/gtest.h>
#include "island-perimeter.cpp"

namespace {
    TEST(islandPerimeterTest, Example1) {      // NOLINT
        std::vector<std::vector<int>> grid = {{0, 1, 0, 0},
                                              {1, 1, 1, 0},
                                              {0, 1, 0, 0},
                                              {1, 1, 0, 0}};
        auto ans = Solution::islandPerimeter(grid);
        decltype(ans) correctAns = 16;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(islandPerimeterTest, Example2) {      // NOLINT
        std::vector<std::vector<int>> grid = {{1}};
        auto ans = Solution::islandPerimeter(grid);
        decltype(ans) correctAns = 4;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(islandPerimeterTest, Example3) {      // NOLINT
        std::vector<std::vector<int>> grid = {{1, 0}};
        auto ans = Solution::islandPerimeter(grid);
        decltype(ans) correctAns = 4;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(islandPerimeterTest, Test0) {      // NOLINT
        std::vector<std::vector<int>> grid = {{1, 1}};
        auto ans = Solution::islandPerimeter(grid);
        decltype(ans) correctAns = 6;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
