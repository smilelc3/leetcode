//
// Created by smile on 2021/4/19.
//


#include <gtest/gtest.h>
#include "word-ladder.cpp"

namespace {
    TEST(ladderLengthTest, Example1) {
        std::string beginWord = "hit", endWord = "cog";
        std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
        auto ans = (new Solution)->ladderLength(beginWord, endWord, wordList);
        auto rightAns = 5;
        ASSERT_EQ(ans, rightAns);
    }


    TEST(ladderLengthTest, Example2) {
        std::string beginWord = "hit", endWord = "cog";
        std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log"};
        auto ans = (new Solution)->ladderLength(beginWord, endWord, wordList);
        auto rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
