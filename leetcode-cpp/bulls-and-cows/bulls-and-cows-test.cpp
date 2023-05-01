//
// Created by smile on 2023/5/1.
//

#include <gtest/gtest.h>
#include "bulls-and-cows.cpp"

namespace {
    TEST(getHintTest, Example1) {
        std::string secret = "1807", guess = "7810";
        auto ans = Solution::getHint(secret, guess);
        decltype(ans) correctAns = "1A3B";
        ASSERT_EQ(ans, correctAns);
    }

    TEST(getHintTest, Example2) {
        std::string secret = "1123", guess = "0111";
        auto ans = Solution::getHint(secret, guess);
        decltype(ans) correctAns = "1A1B";
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}