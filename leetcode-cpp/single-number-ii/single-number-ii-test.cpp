#include <gtest/gtest.h>
#include <vector>
#include "single-number-ii.cpp"

namespace {
    TEST(singleNumberTest, Example1) {
        auto nums = std::vector<int>{2, 2, 3, 2};
        int ans = Solution::singleNumber(nums);
        int rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }


    TEST(singleNumberTest, Example2) {
        auto nums = std::vector<int>{0, 1, 0, 1, 0, 1, 99};
        int ans = Solution::singleNumber(nums);
        int rightAns = 99;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
