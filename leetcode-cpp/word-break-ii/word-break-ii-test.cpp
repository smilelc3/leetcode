//
// Created by smile on 2021/5/13.
//

#include <gtest/gtest.h>
#include <algorithm>
#include "word-break-ii.cpp"

namespace {
    TEST(wordBreakTest, Example1) { // NOLINT
        std::string s = "catsanddog";
        auto wordDict = std::vector<std::string>{"cat", "cats", "and", "sand", "dog"};
        auto ans = Solution().wordBreak(s, wordDict);
        decltype(ans) rightAns = {"cats and dog", "cat sand dog"};
        std::sort(
                ans.begin(),
                ans.end(),
                [](const std::string &a, const std::string &b) {
                    return a > b;
                }
        );
        std::sort(
                rightAns.begin(),
                rightAns.end(),
                [](const std::string &a, const std::string &b) {
                    return a > b;
                }
        );
        ASSERT_EQ(ans, rightAns);
    }

    TEST(wordBreakTest, Example2) { // NOLINT
        std::string s = "pineapplepenapple";
        auto wordDict = std::vector<std::string>{"apple","pen","applepen","pine","pineapple"};
        auto ans = Solution().wordBreak(s, wordDict);
        decltype(ans) rightAns = {"pine apple pen apple","pineapple pen apple","pine applepen apple"};
        std::sort(
                ans.begin(),
                ans.end(),
                [](const std::string &a, const std::string &b) {
                    return a > b;
                }
        );
        std::sort(
                rightAns.begin(),
                rightAns.end(),
                [](const std::string &a, const std::string &b) {
                    return a > b;
                }
        );
        ASSERT_EQ(ans, rightAns);
    }

    TEST(wordBreakTest, Example3) { // NOLINT
        std::string s = "catsandog";
        auto wordDict = std::vector<std::string>{"cats","dog","sand","and","cat"};
        auto ans = Solution().wordBreak(s, wordDict);
        decltype(ans) rightAns = {};
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
