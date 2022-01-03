//
// Created by smile on 2022/1/3.
//

#include <gtest/gtest.h>
#include <vector>
#include "ambiguous-coordinates.cpp"

namespace {
    TEST(ambiguousCoordinatesTest, Example1) {     // NOLINT
        auto s = "(123)";
        auto ans = Solution::ambiguousCoordinates(s);
        decltype(ans) correctAns = {"(1, 2.3)", "(1, 23)", "(1.2, 3)", "(12, 3)"};
        std::sort(ans.begin(), ans.end());
        std::sort(correctAns.begin(), correctAns.end());
        ASSERT_EQ(ans, correctAns);
    }

    TEST(ambiguousCoordinatesTest, Example2) {     // NOLINT
        auto s = "(0123)";
        auto ans = Solution::ambiguousCoordinates(s);
        decltype(ans) correctAns = {"(0, 1.23)", "(0, 12.3)", "(0, 123)", "(0.1, 2.3)", "(0.1, 23)", "(0.12, 3)"};
        std::sort(ans.begin(), ans.end());
        std::sort(correctAns.begin(), correctAns.end());
        ASSERT_EQ(ans, correctAns);
    }

    TEST(ambiguousCoordinatesTest, Test0) {     // NOLINT
        auto s = "(100)";
        auto ans = Solution::ambiguousCoordinates(s);
        decltype(ans) correctAns = {"(10, 0)"};
        std::sort(ans.begin(), ans.end());
        std::sort(correctAns.begin(), correctAns.end());
        ASSERT_EQ(ans, correctAns);
    }

    TEST(ambiguousCoordinatesTest, Test1) {     // NOLINT
        auto s = "(0010)";
        auto ans = Solution::ambiguousCoordinates(s);
        decltype(ans) correctAns = {"(0.01, 0)"};
        std::sort(ans.begin(), ans.end());
        std::sort(correctAns.begin(), correctAns.end());
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}