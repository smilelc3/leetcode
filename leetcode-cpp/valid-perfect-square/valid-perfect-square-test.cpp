//
// Created by smile on 2023/4/15.
//

#include <gtest/gtest.h>
#include "valid-perfect-square.cpp"

namespace {
    TEST(isPerfectSquareTest, Example1) {      // NOLINT
        int num = 16;
        ASSERT_TRUE(Solution::isPerfectSquare(num));
    }

    TEST(isPerfectSquareTest, Example2) {      // NOLINT
        int num = 14;
        ASSERT_FALSE(Solution::isPerfectSquare(num));
    }
    
    TEST(isPerfectSquareTest, Example3) {      // NOLINT
        int num = 9;
        ASSERT_TRUE(Solution::isPerfectSquare(num));
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
