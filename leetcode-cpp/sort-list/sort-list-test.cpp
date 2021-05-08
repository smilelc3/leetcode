//
// Created by smile on 2021/4/9.
//
#include <gtest/gtest.h>
#include <vector>

#include "sort-list.cpp"

namespace {
    TEST(sortListTest, Example1) {
        auto head = GenLinksByNums({4, 2, 3, 1});
        auto ans = Solution::sortList(head);
        auto rightAns = GenLinksByNums({1, 2, 3, 4});
        ASSERT_TRUE(isSameList(rightAns, ans));
    }

    TEST(sortListTest, Example2) {
        auto head = GenLinksByNums({-1, 5, 3, 4, 0});
        auto ans = Solution::sortList(head);
        auto rightAns = GenLinksByNums({-1, 0, 3, 4, 5});
        ASSERT_TRUE(isSameList(rightAns, ans));
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}