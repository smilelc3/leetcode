//
// Created by smile on 2022/3/22.
//

#include <gtest/gtest.h>
#include "sort-characters-by-frequency.cpp"

namespace {
    TEST(frequencySortTest, Example1) {      // NOLINT
        std::string s = "tree";
        auto ans = Solution::frequencySort(s);
        decltype(ans) correctAns = "eert";
        ASSERT_EQ(ans, correctAns);
    }

    TEST(frequencySortTest, Example2) {      // NOLINT
        std::string s = "cccaaa";
        auto ans = Solution::frequencySort(s);
        decltype(ans) correctAns = "aaaccc";
        ASSERT_EQ(ans, correctAns);
    }

    TEST(frequencySortTest, Example3) {      // NOLINT
        std::string s = "Aabb";
        auto ans = Solution::frequencySort(s);
        decltype(ans) correctAns = "bbAa";
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}