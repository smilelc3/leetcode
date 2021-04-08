//
// Created by smile on 2021/4/8.
//

#include <gtest/gtest.h>
#include <vector>
#include "pascals-triangle.cpp"

namespace {
    TEST(generateTest, Example1) {
        int numRows = 5;
        auto ans = Solution::generate(numRows);
        auto rightAns = std::vector<std::vector<int>>{{1},
                                                      {1, 1},
                                                      {1, 2, 1},
                                                      {1, 3, 3, 1},
                                                      {1, 4, 6, 4, 1}};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(generateTest, Example2) {
        int numRows = 1;
        auto ans = Solution::generate(numRows);
        auto rightAns = std::vector<std::vector<int>>{{1}};
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}