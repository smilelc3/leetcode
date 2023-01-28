//
// Created by lcsmile on 2023/1/18.
//

#include <gtest/gtest.h>
#include <vector>
#include "queries-on-number-of-points-inside-a-circle.cpp"

namespace {
    TEST(ccountPointsTest, Example1) {     // NOLINT
        std::vector<std::vector<int>> points = {{1, 3},
                                                {3, 3},
                                                {5, 3},
                                                {2, 2}};
        std::vector<std::vector<int>> queries = {{2, 3, 1},
                                                 {4, 3, 1},
                                                 {1, 1, 2}};
        auto ans = Solution().countPoints(points, queries);
        decltype(ans) correctAns = {3, 2, 2};
        ASSERT_EQ(ans, correctAns);
    }

    TEST(ccountPointsTest, Example2) {     // NOLINT
        std::vector<std::vector<int>> points = {{1, 1},
                                                {2, 2},
                                                {3, 3},
                                                {4, 4},
                                                {5, 5}};
        std::vector<std::vector<int>> queries = {{1, 2, 2},
                                                 {2, 2, 2},
                                                 {4, 3, 2},
                                                 {4, 3, 3}};
        auto ans = Solution().countPoints(points, queries);
        decltype(ans) correctAns = {2, 3, 2, 4};
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}