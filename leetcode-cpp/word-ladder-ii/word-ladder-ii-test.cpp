//
// Created by smile on 2021/4/19.
//

#include <gtest/gtest.h>
#include "word-ladder-ii.cpp"

namespace {
    TEST(findLaddershTest, Example1) {      // NOLINT
        std::string beginWord = "hit", endWord = "cog";
        std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
        auto ans = Solution().findLadders(beginWord, endWord, wordList);
        decltype(ans) rightAns = {{"hit", "hot", "dot", "dog", "cog"},
                                  {"hit", "hot", "lot", "log", "cog"}};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(findLaddersTest, Example2) {       // NOLINT
        std::string beginWord = "hit", endWord = "cog";
        std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log"};
        auto ans = Solution().findLadders(beginWord, endWord, wordList);
        decltype(ans) rightAns = {};
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
