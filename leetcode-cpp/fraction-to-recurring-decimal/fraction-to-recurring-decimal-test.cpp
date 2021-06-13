//
// Created by smile on 2021/6/12.
//

#include <gtest/gtest.h>
#include "fraction-to-recurring-decimal.cpp"

namespace {
    TEST(fractionToDecimalTest, Example1) {     // NOLINT
        auto numerator = 1, denominator = 2;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "0.5";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, Example2) {     // NOLINT
        auto numerator = 2, denominator = 1;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "2";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, Example3) {     // NOLINT
        auto numerator = 2, denominator = 3;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "0.(6)";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, Example4) {     // NOLINT
        auto numerator = 4, denominator = 333;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "0.(012)";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, Example5) {     // NOLINT
        auto numerator = 1, denominator = 5;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "0.2";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, MyTest0) {     // NOLINT
        auto numerator = 1, denominator = 7;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "0.(142857)";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, MyTest1) {     // NOLINT
        auto numerator = 101, denominator = 7;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "14.(428571)";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, Test0) {     // NOLINT
        auto numerator = 1, denominator = 6;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "0.1(6)";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, Test1) {     // NOLINT
        auto numerator = 1, denominator = 333;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "0.(003)";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, Test2) {     // NOLINT
        auto numerator = 0, denominator = -5;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "0";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, Test3) {     // NOLINT
        auto numerator = -50, denominator = 8;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "-6.25";
        EXPECT_EQ(ans, rightAns);
    }

    TEST(fractionToDecimalTest, Test4) {     // NOLINT
        auto numerator = 1, denominator = 214748364;
        auto ans = Solution().fractionToDecimal(numerator, denominator);
        decltype(ans) rightAns = "0.00(000000465661289042462740251655654056577585848337359161441621040707904997124914069194026549138227660723878669455195477065427143370461252966751355553982241280310754777158628319049732085502639731402098131932683780538602845887105337854867197032523144157689601770377165713821223802198558308923834223016478952081795603341592860749337303449725)";
        EXPECT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
