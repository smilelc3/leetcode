//
// Created by smile on 2023/2/8.
//

#include <gtest/gtest.h>
#include "maximal-square.cpp"

namespace {
    TEST(maximalSquareTest, Example1) {        // NOLINT
        std::vector<std::vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                                 {'1', '0', '1', '1', '1'},
                                                 {'1', '1', '1', '1', '1'},
                                                 {'1', '0', '0', '1', '0'}};
        auto ans = Solution().maximalSquare(matrix);
        decltype(ans) correctAnc = 4;
        ASSERT_EQ(ans, correctAnc);
    }

    TEST(maximalSquareTest, Example2) {        // NOLINT
        std::vector<std::vector<char>> matrix = {{'0', '1'},
                                                 {'1', '0'}};
        auto ans = Solution().maximalSquare(matrix);
        decltype(ans) correctAnc = 1;
        ASSERT_EQ(ans, correctAnc);
    }

    TEST(maximalSquareTest, Example3) {        // NOLINT
        std::vector<std::vector<char>> matrix = {{'0'}};
        auto ans = Solution().maximalSquare(matrix);
        decltype(ans) correctAnc = 0;
        ASSERT_EQ(ans, correctAnc);
    }

    TEST(maximalSquareTest, Test0) {        // NOLINT
        std::vector<std::vector<char>> matrix = {{'0', '0', '0', '1'},
                                                 {'1', '1', '0', '1'},
                                                 {'1', '1', '1', '1'},
                                                 {'0', '1', '1', '1'},
                                                 {'0', '1', '1', '1'}};
        auto ans = Solution().maximalSquare(matrix);
        decltype(ans) correctAnc = 9;
        ASSERT_EQ(ans, correctAnc);
    }

    TEST(maximalSquareTest, Test1) {        // NOLINT
        std::vector<std::vector<char>> matrix = {{'1', '1', '1', '1', '1'},
                                                 {'1', '1', '1', '1', '1'},
                                                 {'0', '0', '0', '0', '0'},
                                                 {'1', '1', '1', '1', '1'},
                                                 {'1', '1', '1', '1', '1'}};
        auto ans = Solution().maximalSquare(matrix);
        decltype(ans) correctAnc = 4;
        ASSERT_EQ(ans, correctAnc);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
