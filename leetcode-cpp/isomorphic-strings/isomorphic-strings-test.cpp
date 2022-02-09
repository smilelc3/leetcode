//
// Created by smile on 2022/2/9.
//

#include <gtest/gtest.h>
#include "isomorphic-strings.cpp"

namespace {
    TEST(isIsomorphicTest, Example1) {      // NOLINT
        std::string s = "egg", t = "add";
        ASSERT_TRUE(Solution().isIsomorphic(s, t));
    }

    TEST(isIsomorphicTest, Example2) {      // NOLINT
        std::string s = "foo", t = "bar";
        ASSERT_FALSE(Solution().isIsomorphic(s, t));
    }

    TEST(isIsomorphicTest, Example3) {      // NOLINT
        std::string s = "paper", t = "title";
        ASSERT_TRUE(Solution().isIsomorphic(s, t));
    }

    TEST(isIsomorphicTest, Test0) {      // NOLINT
        std::string s = "badc", t = "baba";
        ASSERT_FALSE(Solution().isIsomorphic(s, t));
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
