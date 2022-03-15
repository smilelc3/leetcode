//
// Created by smile on 2022/3/15.
//

#include <gtest/gtest.h>
#include <vector>
#include "valid-anagram.cpp"

namespace {
    TEST(isAnagramTest, Example1) {      // NOLINT
        std::string s = "anagram", t = "nagaram";
        ASSERT_TRUE(Solution::isAnagram(s, t));
    }

    TEST(isAnagramTest, Example2) {      // NOLINT
        std::string s = "rat", t = "car";
        ASSERT_FALSE(Solution::isAnagram(s, t));
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
