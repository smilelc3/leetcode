//
// Created by smile on 2021/5/7.
//

#include <gtest/gtest.h>
#include "surrounded-regions.cpp"

namespace {
    TEST(solveTest, Example1) { // NOLINT
        std::vector<std::vector<char>> board = {{'X', 'X', 'X', 'X'},
                                                {'X', 'O', 'O', 'X'},
                                                {'X', 'X', 'O', 'X'},
                                                {'X', 'O', 'X', 'X'}};
        Solution().solve(board);
        std::vector<std::vector<char>> rightAns = {{'X', 'X', 'X', 'X'},
                                                   {'X', 'X', 'X', 'X'},
                                                   {'X', 'X', 'X', 'X'},
                                                   {'X', 'O', 'X', 'X'}};
        ASSERT_EQ(board, rightAns);
    }

    TEST(solveTest, Example2) { // NOLINT
        std::vector<std::vector<char>> board = {{'X'}};
        Solution().solve(board);
        std::vector<std::vector<char>> rightAns = {{'X'}};
        ASSERT_EQ(board, rightAns);
    }

    TEST(solveTest, Test0) { // NOLINT
        std::vector<std::vector<char>> board = {{'O', 'O', 'O'},
                                                {'O', 'O', 'O'},
                                                {'O', 'O', 'O'}};
        Solution().solve(board);
        std::vector<std::vector<char>> rightAns = {{'O', 'O', 'O'},
                                                   {'O', 'O', 'O'},
                                                   {'O', 'O', 'O'}};
        ASSERT_EQ(board, rightAns);
    }

    TEST(solveTest, Test1) { // NOLINT
        std::vector<std::vector<char>> board = {{'O', 'X', 'X', 'O', 'X'},
                                                {'X', 'O', 'O', 'X', 'O'},
                                                {'X', 'O', 'X', 'O', 'X'},
                                                {'O', 'X', 'O', 'O', 'O'},
                                                {'X', 'X', 'O', 'X', 'O'}};
        Solution().solve(board);
        std::vector<std::vector<char>> rightAns = {{'O', 'X', 'X', 'O', 'X'},
                                                   {'X', 'X', 'X', 'X', 'O'},
                                                   {'X', 'X', 'X', 'O', 'X'},
                                                   {'O', 'X', 'O', 'O', 'O'},
                                                   {'X', 'X', 'O', 'X', 'O'}};
        ASSERT_EQ(board, rightAns);
    }

    TEST(solveTest, Test2) { // NOLINT
        std::vector<std::vector<char>> board = {{'X', 'O', 'X'},
                                                {'X', 'O', 'X'},
                                                {'X', 'O', 'X'}};
        Solution().solve(board);
        std::vector<std::vector<char>> rightAns = {{'X', 'O', 'X'},
                                                   {'X', 'O', 'X'},
                                                   {'X', 'O', 'X'}};
        ASSERT_EQ(board, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}