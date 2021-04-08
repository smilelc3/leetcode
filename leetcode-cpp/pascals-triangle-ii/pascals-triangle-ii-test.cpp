//
// Created by smile on 2021/4/8.
//

#include <gtest/gtest.h>
#include <vector>
#include "pascals-triangle-ii.cpp"

namespace {
    TEST(getRowTest, Example1) {
        int rowIndex = 3;
        auto ans = Solution::getRow(rowIndex);
        auto rightAns = std::vector<int>{1, 3, 3, 1};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(getRowTest, Example2) {
        int rowIndex = 0;
        auto ans = Solution::getRow(rowIndex);
        auto rightAns = std::vector<int>{1};
        ASSERT_EQ(ans, rightAns);
    }

    TEST(getRowTest, Example3) {
        int rowIndex = 1;
        auto ans = Solution::getRow(rowIndex);
        auto rightAns = std::vector<int>{1, 1};
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}