//
// Created by smile on 2022/7/22.
//

#include <gtest/gtest.h>
#include "first-bad-version.cpp"

static int globalFirstBadVer;

bool isBadVersion(int version) {
    return version >= globalFirstBadVer;
}
// 配套设置接口
void setFirstBadVer(int firstBadVer) {
    globalFirstBadVer = firstBadVer;
}

namespace {
    TEST(firstBadVersionTest, Example1) {   // NOLINT
        int n = 5, bad = 4;
        setFirstBadVer(bad);
        auto ans = Solution::firstBadVersion(n);
        decltype(ans) rightAns = bad;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(firstBadVersionTest, Example2) {   // NOLINT
        int n = 1, bad = 1;
        setFirstBadVer(bad);
        auto ans = Solution::firstBadVersion(n);
        decltype(ans) rightAns = bad;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(firstBadVersionTest, Test0) {   // NOLINT
        int n = 2126753390, bad = 1702766719;
        setFirstBadVer(bad);
        auto ans = Solution::firstBadVersion(n);
        decltype(ans) rightAns = bad;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(firstBadVersionTest, Test1) {   // NOLINT
        int n = 2147483647, bad = 2147483647;
        setFirstBadVer(bad);
        auto ans = Solution::firstBadVersion(n);
        decltype(ans) rightAns = bad;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}