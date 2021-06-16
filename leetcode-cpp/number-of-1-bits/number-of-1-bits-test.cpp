//
// Created by smile on 2021/6/16.
//

#include <gtest/gtest.h>
#include "number-of-1-bits.cpp"

namespace {
    TEST(hammingWeightTest, Example1) {     // NOLINT
        uint32_t n = 0b00000000000000000000000000001011;
        auto ans = Solution().hammingWeight(n);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(hammingWeightTest, Example2) {     // NOLINT
        uint32_t n = 0b00000000000000000000000010000000;
        auto ans = Solution().hammingWeight(n);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(hammingWeightTest, Example3) {     // NOLINT
        uint32_t n = 0b11111111111111111111111111111101;
        auto ans = Solution().hammingWeight(n);
        decltype(ans) rightAns = 31;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
