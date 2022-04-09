//
// Created by smile on 2022/4/7.
//

#include <gtest/gtest.h>
#include "h-index.cpp"

namespace {
    TEST(hIndexTest, Example1) {      // NOLINT
        std::vector<int> citations = {3, 0, 6, 1, 5};
        auto ans = Solution::hIndex(citations);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(hIndexTest, Example2) {      // NOLINT
        std::vector<int> citations = {1, 3, 1};
        auto ans = Solution::hIndex(citations);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(hIndexTest, Test0) {      // NOLINT
        std::vector<int> citations = {1};
        auto ans = Solution::hIndex(citations);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(hIndexTest, Test1) {      // NOLINT
        std::vector<int> citations = {1, 1};
        auto ans = Solution::hIndex(citations);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

    TEST(hIndexTest, Test2) {      // NOLINT
        std::vector<int> citations = {1, 1, 1};
        auto ans = Solution::hIndex(citations);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
