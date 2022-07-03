//
// Created by smile on 2022/7/2.
//

#include <gtest/gtest.h>
#include <vector>
#include "rectangle-area.cpp"

namespace {
    TEST(computeAreaTest, Example1) {     // NOLINT
        int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
        auto ans = Solution().computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        decltype(ans) rightAns = 45;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(computeAreaTest, Example2) {     // NOLINT
        int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2;
        auto ans = Solution().computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        decltype(ans) rightAns = 16;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(computeAreaTest, Test0) {     // NOLINT
        int ax1 = 0, ay1 = 0, ax2 = 0, ay2 = 0, bx1 = -1, by1 = -1, bx2 = 1, by2 = 1;
        auto ans = Solution().computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        decltype(ans) rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(computeAreaTest, Test1) {     // NOLINT
        int ax1 = -3, ay1 = -3, ax2 = 3, ay2 = -1, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2;
        auto ans = Solution().computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        decltype(ans) rightAns = 24;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(computeAreaTest, Test2) {     // NOLINT
        int ax1 = -5, ay1 = -2, ax2 = 5, ay2 = 1, bx1 = -3, by1 = -3, bx2 = 3, by2 = 3;
        auto ans = Solution().computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        decltype(ans) rightAns = 48;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}