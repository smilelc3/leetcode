//
// Created by smile on 2022/1/2.
//

#include <gtest/gtest.h>
#include <vector>
#include "path-with-maximum-gold.cpp"

namespace {
    TEST(getMaximumGoldTest, Example1) {     // NOLINT
        std::vector<std::vector<int>> grid = {{0, 6, 0},
                                              {5, 8, 7},
                                              {0, 9, 0}};
        auto ans = Solution().getMaximumGold(grid);
        decltype(ans) rightAns = 24;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(getMaximumGoldTest, Example2) {     // NOLINT
        std::vector<std::vector<int>> grid = {{1, 0, 7},
                                              {2, 0, 6},
                                              {3, 4, 5},
                                              {0, 3, 0},
                                              {9, 0, 20}};
        auto ans = Solution().getMaximumGold(grid);
        decltype(ans) rightAns = 28;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(getMaximumGoldTest, Test0) {     // NOLINT
        std::vector<std::vector<int>> grid = {{1, 1, 1, 1, 1},
                                              {1, 0, 1, 0, 1},
                                              {1, 1, 1, 1, 1},
                                              {1, 0, 1, 0, 1},
                                              {1, 1, 1, 1, 1}};
        auto ans = Solution().getMaximumGold(grid);
        decltype(ans) rightAns = 19;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}