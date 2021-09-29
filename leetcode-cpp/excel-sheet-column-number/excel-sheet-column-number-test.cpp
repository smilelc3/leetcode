//
// Created by smile on 2021/6/14.
//

#include <gtest/gtest.h>
#include "excel-sheet-column-number.cpp"

namespace {
    TEST(titleToNumberTest, Example1) {        // NOLINT
        std::string columnTitle = "A";
        auto ans = Solution().titleToNumber(columnTitle);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(titleToNumberTest, Example2) {        // NOLINT
        std::string columnTitle = "AB";
        auto ans = Solution().titleToNumber(columnTitle);
        decltype(ans) rightAns = 28;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(titleToNumberTest, Example3) {        // NOLINT
        std::string columnTitle = "ZY";
        auto ans = Solution().titleToNumber(columnTitle);
        decltype(ans) rightAns = 701;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(titleToNumberTest, Example4) {        // NOLINT
        std::string columnTitle = "FXSHRXW";
        auto ans = Solution().titleToNumber(columnTitle);
        decltype(ans) rightAns = 2147483647;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}