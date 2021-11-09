//
// Created by l30014168 on 2021/11/8.
//

#include <gtest/gtest.h>
#include <vector>
#include "shortest-path-with-alternating-colors.cpp"

namespace {
    TEST(shortestAlternatingPathsTest, Example1) {      // NOLINT
        auto n = 3;
        std::vector<std::vector<int>> red_edges = {{0, 1},
                                                   {1, 2}};
        std::vector<std::vector<int>> blue_edges = {};
        auto ans = Solution().shortestAlternatingPaths(n, red_edges, blue_edges);
        decltype(ans) correctAns = {0, 1, -1};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(shortestAlternatingPathsTest, Example2) {      // NOLINT
        auto n = 3;
        std::vector<std::vector<int>> red_edges = {{0, 1}};
        std::vector<std::vector<int>> blue_edges = {{2, 1}};
        auto ans = Solution().shortestAlternatingPaths(n, red_edges, blue_edges);
        decltype(ans) correctAns = {0, 1, -1};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(shortestAlternatingPathsTest, Example3) {      // NOLINT
        auto n = 3;
        std::vector<std::vector<int>> red_edges = {{1, 0}};
        std::vector<std::vector<int>> blue_edges = {{2, 1}};
        auto ans = Solution().shortestAlternatingPaths(n, red_edges, blue_edges);
        decltype(ans) correctAns = {0, -1, -1};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(shortestAlternatingPathsTest, Example4) {      // NOLINT
        auto n = 3;
        std::vector<std::vector<int>> red_edges = {{0, 1}};
        std::vector<std::vector<int>> blue_edges = {{1, 2}};
        auto ans = Solution().shortestAlternatingPaths(n, red_edges, blue_edges);
        decltype(ans) correctAns = {0, 1, 2};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(shortestAlternatingPathsTest, Example5) {      // NOLINT
        auto n = 3;
        std::vector<std::vector<int>> red_edges = {{0, 1},
                                                   {0, 2}};
        std::vector<std::vector<int>> blue_edges = {{1, 0}};
        auto ans = Solution().shortestAlternatingPaths(n, red_edges, blue_edges);
        decltype(ans) correctAns = {0, 1, 1};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(shortestAlternatingPathsTest, Test0) {      // NOLINT
        auto n = 5;
        std::vector<std::vector<int>> red_edges = {{0, 1},
                                                   {1, 2},
                                                   {2, 3},
                                                   {3, 4}};
        std::vector<std::vector<int>> blue_edges = {{1, 2},
                                                    {2, 3},
                                                    {3, 1}};
        auto ans = Solution().shortestAlternatingPaths(n, red_edges, blue_edges);
        decltype(ans) correctAns = {0, 1, 2, 3, 7};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(shortestAlternatingPathsTest, MyTest0) {      // NOLINT
        auto n = 2;
        std::vector<std::vector<int>> red_edges = {{0, 1}};
        std::vector<std::vector<int>> blue_edges = {{1, 0}};
        auto ans = Solution().shortestAlternatingPaths(n, red_edges, blue_edges);
        decltype(ans) correctAns = {0, 1};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(shortestAlternatingPathsTest, Test1) {      // NOLINT
        auto n = 5;
        std::vector<std::vector<int>> red_edges = {{2, 2},
                                                   {0, 1},
                                                   {0, 3},
                                                   {0, 0},
                                                   {0, 4},
                                                   {2, 1},
                                                   {2, 0},
                                                   {1, 4},
                                                   {3, 4}};
        std::vector<std::vector<int>> blue_edges = {{1, 3},
                                                    {0, 0},
                                                    {0, 3},
                                                    {4, 2},
                                                    {1, 0}};
        auto ans = Solution().shortestAlternatingPaths(n, red_edges, blue_edges);
        decltype(ans) correctAns = {0, 1, 2, 1, 1};
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {      // NOLINT
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
