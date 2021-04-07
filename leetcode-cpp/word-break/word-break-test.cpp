//
// Created by smile on 2021/4/7.
//

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "word-break.cpp"

namespace {
    TEST(wordBreakTest, Example1) {
        std::string s = "leetcode";
        auto wordDict = std::vector<std::string>{"leet", "code"};
        auto ans = Solution::wordBreak(s, wordDict);
        ASSERT_TRUE(ans);
    }


    TEST(wordBreakTest, Example2) {
        std::string s = "applepenapple";
        auto wordDict = std::vector<std::string>{"apple", "pen"};
        auto ans = Solution::wordBreak(s, wordDict);
        ASSERT_TRUE(ans);
    }


    TEST(wordBreakTest, Example3) {
        std::string s = "catsandog";
        auto wordDict = std::vector<std::string>{"cats", "dog", "sand", "and", "cat"};
        auto ans = Solution::wordBreak(s, wordDict);
        ASSERT_FALSE(ans);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
