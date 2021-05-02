//
// Created by smile on 2021/5/2.
//

#include <gtest/gtest.h>
#include "evaluate-reverse-polish-notation.cpp"

namespace {
    TEST(evalRPNTest, Example1) {
        std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
        auto ans = Solution().evalRPN(tokens);
        auto rightAns = 9;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(evalRPNTest, Example2) {
        std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
        auto ans = Solution().evalRPN(tokens);
        auto rightAns = 6;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(evalRPNTest, Example3) {
        std::vector<std::string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        auto ans = Solution().evalRPN(tokens);
        auto rightAns = 22;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(evalRPNTest, MyTest0) {
        std::vector<std::string> tokens = {"10", "6", "%"};
        auto ans = Solution().evalRPN(tokens);
        auto rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(evalRPNTest, MyTest1) {
        std::vector<std::string> tokens = {"3", "2", "^"};
        auto ans = Solution().evalRPN(tokens);
        auto rightAns = 9;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}