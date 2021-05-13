//
// Created by smile on 2021/5/13.
//

#include <gtest/gtest.h>
#include <vector>
#include "reverse-words-in-a-string.cpp"

namespace {
    TEST(reverseWordsTest, Example1) {  // NOLINT
        std::string s = "the sky is blue";
        auto ans = Solution().reverseWords(s);
        decltype(ans) rightAns = "blue is sky the";
        ASSERT_EQ(ans, rightAns);
    }


    TEST(reverseWordsTest, Example2) {  // NOLINT
        std::string s = "  hello world  ";
        auto ans = Solution().reverseWords(s);
        decltype(ans) rightAns = "world hello";
        ASSERT_EQ(ans, rightAns);
    }

    TEST(reverseWordsTest, Example3) {  // NOLINT
        std::string s = "a good   example";
        auto ans = Solution().reverseWords(s);
        decltype(ans) rightAns = "example good a";
        ASSERT_EQ(ans, rightAns);
    }

    TEST(reverseWordsTest, Test0) {  // NOLINT
        std::string s = "F R  I   E    N     D      S      ";
        auto ans = Solution().reverseWords(s);
        decltype(ans) rightAns = "S D N E I R F";
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
