//
// Created by smile on 2022/7/22.
//

#include <gtest/gtest.h>
#include "word-pattern.cpp"

namespace {
    TEST(wordPatternTest, Example1) {      // NOLINT
        std::string pattern = "abba", s = "dog cat cat dog";
        ASSERT_TRUE(Solution().wordPattern(pattern, s));
    }

    TEST(wordPatternTest, Example2) {      // NOLINT
        std::string pattern = "abba", s = "dog cat cat fish";
        ASSERT_FALSE(Solution().wordPattern(pattern, s));
    }

    TEST(wordPatternTest, Example3) {      // NOLINT
        std::string pattern = "aaaa", s = "dog cat cat dog";
        ASSERT_FALSE(Solution().wordPattern(pattern, s));
    }

    TEST(wordPatternTest, Test0) {      // NOLINT
        std::string pattern = "abba", s = "dog dog dog dog";
        ASSERT_FALSE(Solution().wordPattern(pattern, s));
    }

    TEST(wordPatternTest, Test1) {      // NOLINT
        std::string pattern = "aba", s = "cat cat cat dog";
        ASSERT_FALSE(Solution().wordPattern(pattern, s));
    }

    TEST(wordPatternTest, Test2) {      // NOLINT
        std::string pattern = "jquery", s = "jquery";
        ASSERT_FALSE(Solution().wordPattern(pattern, s));
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
