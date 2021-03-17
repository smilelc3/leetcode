#include <gtest/gtest.h>
#include <vector>
#include "single-number.cpp"

namespace {
    TEST(singleNumberTest, Example1) {
        auto nums = std::vector<int>{2, 2, 1};
        int ans = Solution::singleNumber(nums);
        int rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }


    TEST(singleNumberTest, Example2) {
        auto nums = std::vector<int>{4, 1, 2, 1, 2};
        int ans = Solution::singleNumber(nums);
        int rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(singleNumberTest, Example3) {
        auto nums = std::vector<int>{1};
        int ans = Solution::singleNumber(nums);
        int rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
