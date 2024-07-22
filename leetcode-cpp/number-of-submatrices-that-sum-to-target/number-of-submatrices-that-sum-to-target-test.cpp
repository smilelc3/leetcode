//
// Created by smile on 2024/7/18.
//


#include <gtest/gtest.h>
#include <vector>
#include "number-of-submatrices-that-sum-to-target.cpp"

namespace {
    TEST(numSubmatrixSumTargetTest, Example1) {     // NOLINT
        std::vector<std::vector<int>> matrix = {{0, 1, 0},
                                                {1, 1, 1},
                                                {0, 1, 0}};
        int target = 0;
        auto ans = Solution().numSubmatrixSumTarget(matrix, target);
        decltype(ans) correctAns = 4;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(numSubmatrixSumTargetTest, Example2) {     // NOLINT
        std::vector<std::vector<int>> matrix = {{1,  -1},
                                                {-1, 1}};
        int target = 0;
        auto ans = Solution().numSubmatrixSumTarget(matrix, target);
        decltype(ans) correctAns = 5;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(numSubmatrixSumTargetTest, Example3) {     // NOLINT
        std::vector<std::vector<int>> matrix = {{904}};
        int target = 0;
        auto ans = Solution().numSubmatrixSumTarget(matrix, target);
        decltype(ans) correctAns = 0;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
