//
// Created by smile on 2021/4/9.
//
#include <gtest/gtest.h>
#include <string>

#include "valid-palindrome.cpp"

namespace {
    TEST(isPalindromeTest, Example1) {      // NOLINT
        std::string s = "A man, a plan, a canal: Panama";
        auto ans = Solution::isPalindrome(s);
        ASSERT_TRUE(ans);
    }

    TEST(isPalindromeTest, Example2) {      // NOLINT
        std::string s = "race a car";
        auto ans = Solution::isPalindrome(s);
        ASSERT_FALSE(ans);
    }

    TEST(isPalindromeTest, Test0) {         // NOLINT
        std::string s = "aa";
        auto ans = Solution::isPalindrome(s);
        ASSERT_TRUE(ans);
    }

    TEST(isPalindromeTest, Test1) {     // NOLINT
        std::string s = "0P";
        auto ans = Solution::isPalindrome(s);
        ASSERT_FALSE(ans);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
