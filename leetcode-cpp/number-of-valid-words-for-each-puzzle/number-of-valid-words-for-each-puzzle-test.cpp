//
// Created by smile on 25-12-10.
//

#include <gtest/gtest.h>
#include <vector>
#include "number-of-valid-words-for-each-puzzle.cpp"

namespace {
    TEST(findNumOfValidWordsTest, Example1) {
        std::vector<std::string> words = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
        std::vector<std::string> puzzles = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
        auto ans = Solution().findNumOfValidWords(words, puzzles);
        decltype(ans) correctAns = {1, 1, 3, 2, 4, 0};
        ASSERT_EQ(ans, correctAns);
    }


    TEST(findNumOfValidWordsTest, TEST0) {
        std::vector<std::string> words = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
        std::vector<std::string> puzzles = {"gaswxyz"};
        auto ans = Solution().findNumOfValidWords(words, puzzles);
        decltype(ans) correctAns = {0};
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
