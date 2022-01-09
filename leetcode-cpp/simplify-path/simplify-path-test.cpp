//
// Created by smile on 2022/1/9.
//

#include <gtest/gtest.h>
#include "simplify-path.cpp"

namespace {
    TEST(simplifyPathTest, Example1) {      // NOLINT
        auto path = "/../";
        auto ans = Solution::simplifyPath(path);
        decltype(ans) correctAns = "/";
        ASSERT_EQ(ans, correctAns);
    }

    TEST(simplifyPathTest, Example2) {      // NOLINT
        auto path = "/home/";
        auto ans = Solution::simplifyPath(path);
        decltype(ans) correctAns = "/home";
        ASSERT_EQ(ans, correctAns);
    }

    TEST(simplifyPathTest, Example3) {      // NOLINT
        auto path = "/home//foo/";
        auto ans = Solution::simplifyPath(path);
        decltype(ans) correctAns = "/home/foo";
        ASSERT_EQ(ans, correctAns);
    }

    TEST(simplifyPathTest, Test0) {      // NOLINT
        auto path = "/a/./b/../../c/";
        auto ans = Solution::simplifyPath(path);
        decltype(ans) correctAns = "/c";
        ASSERT_EQ(ans, correctAns);
    }

    TEST(simplifyPathTest, Test1) {      // NOLINT
        auto path = "/a//b////c/d//././/..";
        auto ans = Solution::simplifyPath(path);
        decltype(ans) correctAns = "/a/b/c";
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
