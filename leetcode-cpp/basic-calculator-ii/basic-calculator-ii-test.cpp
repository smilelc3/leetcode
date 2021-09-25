//
// Created by smile on 2021/9/25.
//

#include <gtest/gtest.h>
#include "basic-calculator-ii.cpp"

namespace {
    TEST(calculateTest, Example1) {     // NOLINT
        std::string s = "3+2*2";
        auto ans = Solution().calculate(s);
        decltype(ans) rightAns = 7;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(calculateTest, Example2) {     // NOLINT
        std::string s = " 3/2 ";
        auto ans = Solution().calculate(s);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(calculateTest, Example3) {     // NOLINT
        std::string s = " 3+5 / 2 ";
        auto ans = Solution().calculate(s);
        decltype(ans) rightAns = 5;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
