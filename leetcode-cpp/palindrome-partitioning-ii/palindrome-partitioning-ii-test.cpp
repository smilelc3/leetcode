//
// Created by smile on 2021/5/17.
//

#include <gtest/gtest.h>
#include <vector>
#include "palindrome-partitioning-ii.cpp"

namespace {
    TEST(minCutTest, Example1) {     // NOLINT
        std::string s = "aab";
        auto ans = Solution().minCut(s);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(minCutTest, Example2) {     // NOLINT
        std::string s = "a";
        auto ans = Solution().minCut(s);
        decltype(ans) rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(minCutTest, Example3) {     // NOLINT
        std::string s = "ab";
        auto ans = Solution().minCut(s);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
