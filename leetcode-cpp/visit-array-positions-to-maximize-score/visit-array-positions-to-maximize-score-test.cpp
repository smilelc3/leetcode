//
// Created by smile on 24-6-15.
//


#include <gtest/gtest.h>
#include "visit-array-positions-to-maximize-score.cpp"

namespace {
    TEST(maxScoreTest, Example1) { // NOLINT
        std::vector nums = {2, 3, 6, 1, 9, 2};
        int x = 5;
        auto ans = Solution().maxScore(nums, x);
        decltype(ans) correctAns = 13;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(maxScoreTest, Example2) { // NOLINT
        std::vector nums = {2, 4, 6, 8};
        int x = 3;
        auto ans = Solution().maxScore(nums, x);
        decltype(ans) correctAns = 20;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(maxScoreTest, Test0) { // NOLINT
        std::vector nums = {
            18, 13, 60, 61, 57, 21, 10, 98, 51, 3, 13, 36, 72, 70, 68, 62, 52, 83, 63, 63, 53, 42, 59, 98, 95, 48, 22,
            64, 94, 80, 14, 14
        };
        int x = 2;
        auto ans = Solution().maxScore(nums, x);
        decltype(ans) correctAns = 1633;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(maxScoreTest, Test1) { // NOLINT
        std::vector nums = {8, 50, 65, 85, 8, 73, 55, 50, 29, 95, 5, 68, 52, 79};
        int x = 74;
        auto ans = Solution().maxScore(nums, x);
        decltype(ans) correctAns = 470;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(maxScoreTest, Test2) { // NOLINT
        std::vector nums = {
            99, 88, 98, 15, 34, 40, 29, 81, 2, 6, 12, 9, 82, 93, 5, 81, 84, 71, 83, 31, 12, 22, 9, 65, 56, 9, 68, 79,
            39, 84, 50, 7, 25, 3, 49
        };
        int x = 19;
        auto ans = Solution().maxScore(nums, x);
        decltype(ans) correctAns = 1363;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(maxScoreTest, MyTest0) { // NOLINT
        std::vector nums = {18, 13};
        int x = 2;
        auto ans = Solution().maxScore(nums, x);
        decltype(ans) correctAns = 29;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(maxScoreTest, MyTest1) { // NOLINT
        std::vector nums = {8, 50, 65};
        int x = 74;
        auto ans = Solution().maxScore(nums, x);
        decltype(ans) correctAns = 58;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
