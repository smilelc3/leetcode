//
// Created by smile on 24-6-1.
//

#include <gtest/gtest.h>
#include "solve-the-equation.cpp"

namespace {
    TEST(solveEquationTest, Example1) {
        std::string equation = "x+5-3+x=6+x-2";
        auto ans = Solution::solveEquation(equation);
        decltype(ans) correctAns = "x=2";
        ASSERT_EQ(ans, correctAns);
    }

    TEST(solveEquationTest, Example2) {
        std::string equation = "x=x";
        auto ans = Solution::solveEquation(equation);
        decltype(ans) correctAns = "Infinite solutions";
        ASSERT_EQ(ans, correctAns);
    }

    TEST(solveEquationTest, Example3) {
        std::string equation = "2x=x";
        auto ans = Solution::solveEquation(equation);
        decltype(ans) correctAns = "x=0";
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
