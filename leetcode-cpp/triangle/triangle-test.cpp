//
// Created by smile on 2021/4/9.
//

#include <gtest/gtest.h>
#include <vector>
#include "triangle.cpp"

namespace {
    TEST(minimumTotalTest, Example1) {      // NOLINT
        std::vector<std::vector<int>> triangle = {{2},
                                                  {3, 4},
                                                  {6, 5, 7},
                                                  {4, 1, 8, 3}};
        auto ans = Solution::minimumTotal(triangle);
        auto rightAns = 11;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(minimumTotalTest, Example2) {      // NOLINT
        std::vector<std::vector<int>> triangle = {{-10}};
        auto ans = Solution::minimumTotal(triangle);
        auto rightAns = -10;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
