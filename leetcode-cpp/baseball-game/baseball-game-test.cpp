//
// Created by smile on 2022/1/17.
//

#include <gtest/gtest.h>
#include "baseball-game.cpp"

namespace {
    TEST(calPointsTest, Example1) {     // NOLINT
        std::vector<std::string> ops = {"5", "2", "C", "D", "+"};
        auto ans = Solution::calPoints(ops);
        decltype(ans) correctAns = 30;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(calPointsTest, Example2) {     // NOLINT
        std::vector<std::string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
        auto ans = Solution::calPoints(ops);
        decltype(ans) correctAns = 27;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(calPointsTest, Example3) {     // NOLINT
        std::vector<std::string> ops = {"1"};
        auto ans = Solution::calPoints(ops);
        decltype(ans) correctAns = 1;
        ASSERT_EQ(ans, correctAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
