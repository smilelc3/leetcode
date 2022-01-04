//
// Created by smile on 2022/1/4.
//

#include <gtest/gtest.h>
#include <vector>
#include "search-a-2d-matrix-ii.cpp"

namespace {
    TEST(searchMatrixTest, MyTest0) {      // NOLINT
        std::vector<std::vector<int>> matrix = {{1,  4,  7,  11, 15},
                                                {2,  5,  8,  12, 19},
                                                {3,  6,  9,  16, 22},
                                                {10, 13, 14, 17, 24},
                                                {18, 21, 23, 26, 30}};
        ASSERT_TRUE(Solution::searchMatrix(matrix, 9));
    }

    TEST(searchMatrixTest, MyTest1) {      // NOLINT
        std::vector<std::vector<int>> matrix = {{1,  4,  7,  11, 15},
                                                {2,  5,  8,  12, 19},
                                                {3,  6,  9,  16, 22},
                                                {10, 13, 14, 17, 24},
                                                {18, 21, 23, 26, 30}};
        ASSERT_TRUE(Solution::searchMatrix(matrix, 12));
    }

    TEST(searchMatrixTest, MyTest2) {      // NOLINT
        std::vector<std::vector<int>> matrix = {{1,  4,  7,  11, 15},
                                                {2,  5,  8,  12, 19},
                                                {3,  6,  9,  16, 22},
                                                {10, 13, 14, 17, 24},
                                                {18, 21, 23, 26, 30}};
        ASSERT_FALSE(Solution::searchMatrix(matrix, 20));
    }

    TEST(searchMatrixTest, MyTest3) {      // NOLINT
        std::vector<std::vector<int>> matrix = {};
        ASSERT_FALSE(Solution::searchMatrix(matrix, 0));
    }

    TEST(searchMatrixTest, MyTest4) {      // NOLINT
        std::vector<std::vector<int>> matrix = {{}};
        ASSERT_FALSE(Solution::searchMatrix(matrix, 0));
    }

    TEST(searchMatrixTest, Test0) {      // NOLINT
        std::vector<std::vector<int>> matrix = {{1, 3, 5}};
        ASSERT_FALSE(Solution::searchMatrix(matrix, -1));
    }

    TEST(searchMatrixTest, Test1) {      // NOLINT
        std::vector<std::vector<int>> matrix = {{3, 5,  9,  9,  14},
                                                {7, 8,  11, 15, 15},
                                                {8, 10, 16, 16, 17}};
        ASSERT_FALSE(Solution::searchMatrix(matrix, 12));
    }

    TEST(searchMatrixTest, Test2) {      // NOLINT
        std::vector<std::vector<int>> matrix = {{3,  5,  9,  9,  9,  11},
                                                {5,  8,  13, 13, 16, 17},
                                                {10, 10, 14, 14, 16, 19},
                                                {15, 18, 20, 24, 26, 26},
                                                {20, 24, 29, 32, 37, 41}};
        ASSERT_TRUE(Solution::searchMatrix(matrix, 32));
    }

    TEST(searchMatrixTest, Test3) {      // NOLINT
        std::vector<std::vector<int>> matrix = {{-5}};
        ASSERT_TRUE(Solution::searchMatrix(matrix, -5));
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}