//
// Created by smile on 2021/6/20.
//

#include <gtest/gtest.h>
#include "basic-calculator.cpp"

namespace {
    TEST(calculateTest, Example1) {     // NOLINT
        std::string s = "1 + 1";
        auto ans = Solution().calculate(s);
        decltype(ans) rightAns = 2;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(calculateTest, Example2) {     // NOLINT
        std::string s = "2-1 + 2";
        auto ans = Solution().calculate(s);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(calculateTest, Example3) {     // NOLINT
        std::string s = "(1+(4+5+2)-3)+(6+8)";
        auto ans = Solution().calculate(s);
        decltype(ans) rightAns = 23;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(calculateTest, Example4) {     // NOLINT
        std::string s = "48 + -48";
        auto ans = Solution().calculate(s);
        decltype(ans) rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
