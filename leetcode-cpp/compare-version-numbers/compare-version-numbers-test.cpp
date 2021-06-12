//
// Created by smile on 2021/6/11.
//

#include <gtest/gtest.h>
#include "compare-version-numbers.cpp"

namespace {
    TEST(compareVersionTest, Example1) {        // NOLINT
        std::string version1 = "1.01";
        std::string version2 = "1.001";
        auto ans = Solution().compareVersion(version1, version2);
        auto rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(compareVersionTest, Example2) {        // NOLINT
        std::string version1 = "1.0";
        std::string version2 = "1.0.0";
        auto ans = Solution().compareVersion(version1, version2);
        auto rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(compareVersionTest, Example3) {        // NOLINT
        std::string version1 = "0.1";
        std::string version2 = "1.1";
        auto ans = Solution().compareVersion(version1, version2);
        auto rightAns = -1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(compareVersionTest, Example4) {        // NOLINT
        std::string version1 = "1.0.1";
        std::string version2 = "1";
        auto ans = Solution().compareVersion(version1, version2);
        auto rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(compareVersionTest, Example5) {        // NOLINT
        std::string version1 = "7.5.2.4";
        std::string version2 = "7.5.3";
        auto ans = Solution().compareVersion(version1, version2);
        auto rightAns = -1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(compareVersionTest, Test0) {        // NOLINT
        std::string version1 = "0.1";
        std::string version2 = "1.1";
        auto ans = Solution().compareVersion(version1, version2);
        auto rightAns = -1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(compareVersionTest, Test1) {        // NOLINT
        std::string version1 = "1.00.1";
        std::string version2 = "1.0.2";
        auto ans = Solution().compareVersion(version1, version2);
        auto rightAns = -1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(compareVersionTest, Test2) {        // NOLINT
        std::string version1 = "1.2";
        std::string version2 = "1.10";
        auto ans = Solution().compareVersion(version1, version2);
        auto rightAns = -1;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}