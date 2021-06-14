//
// Created by smile on 2021/6/13.
//

#include <gtest/gtest.h>
#include "excel-sheet-column-title.cpp"

namespace {
    TEST(convertToTitleTest, Example1) {        // NOLINT
        int columnNumber = 1;
        auto ans = Solution().convertToTitle(columnNumber);
        decltype(ans) rightAns = "A";
        ASSERT_EQ(ans, rightAns);
    }

    TEST(convertToTitleTest, Example2) {        // NOLINT
        int columnNumber = 28;
        auto ans = Solution().convertToTitle(columnNumber);
        decltype(ans) rightAns = "AB";
        ASSERT_EQ(ans, rightAns);
    }

    TEST(convertToTitleTest, Example3) {        // NOLINT
        int columnNumber = 701;
        auto ans = Solution().convertToTitle(columnNumber);
        decltype(ans) rightAns = "ZY";
        ASSERT_EQ(ans, rightAns);
    }

    TEST(convertToTitleTest, Example4) {        // NOLINT
        int columnNumber = 2147483647;
        auto ans = Solution().convertToTitle(columnNumber);
        decltype(ans) rightAns = "FXSHRXW";
        ASSERT_EQ(ans, rightAns);
    }

    TEST(convertToTitleTest, MyTest0) {        // NOLINT
        int columnNumber = 27;
        auto ans = Solution().convertToTitle(columnNumber);
        decltype(ans) rightAns = "AA";
        ASSERT_EQ(ans, rightAns);
    }




    TEST(convertToTitleTest, Test0) {        // NOLINT
        int columnNumber = 52;
        auto ans = Solution().convertToTitle(columnNumber);
        decltype(ans) rightAns = "AZ";
         ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}