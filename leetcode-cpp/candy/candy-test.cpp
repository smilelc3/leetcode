//
// Created by smile on 2021/5/9.
//

#include <gtest/gtest.h>
#include "candy.cpp"

namespace {
    TEST(candyTest, Example1) {
        std::vector<int> ratings = {1, 0, 2};
        auto ans = Solution().candy(ratings);
        auto rightAns = 5;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(candyTest, Example2) {
        std::vector<int> ratings = {1, 2, 2};
        auto ans = Solution().candy(ratings);
        auto rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}