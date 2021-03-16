#include <gtest/gtest.h>
#include <vector>
#include "gray-code.cpp"

namespace {
    TEST(grayCodeTest, Example1) {
        int n = 2;
        auto ans = Solution::grayCode(n);
        std::vector<int> rightAns = {0, 1, 3, 2};
        ASSERT_EQ(ans, rightAns);
    }


    TEST(grayCodeTest, Example2) {
        int n = 1;
        auto ans = Solution::grayCode(n);
        std::vector<int> rightAns = {0, 1};
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
