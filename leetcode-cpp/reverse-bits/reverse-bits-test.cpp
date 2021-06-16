//
// Created by smile on 2021/6/16.
//

//
// Created by smile on 2021/6/16.
//

#include <gtest/gtest.h>
#include "reverse-bits.cpp"

namespace {
    TEST(reverseBitsTest, Example1) {     // NOLINT
        uint32_t n = 0b00000010100101000001111010011100;
        auto ans = Solution().reverseBits(n);
        decltype(ans) rightAns = 0b00111001011110000010100101000000;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(reverseBitsTest, Example2) {     // NOLINT
        uint32_t n = 0b11111111111111111111111111111101;
        auto ans = Solution().reverseBits(n);
        decltype(ans) rightAns = 0b10111111111111111111111111111111;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
