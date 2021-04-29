//
// Created by smile on 2021/4/29.
//


#include <gtest/gtest.h>
#include "reverse-linked-list.cpp"

namespace {
    TEST(reverseListTest, Example1) {
        auto head = GenLinksByNums({1, 2, 3, 4, 5});
        auto ans = Solution().reverseList(head);
        auto rightAns = GenLinksByNums({5, 4, 3, 2, 1});
        ASSERT_TRUE(isSameList(rightAns, ans));
    }

    TEST(reverseListTest, Example2) {
        auto head = GenLinksByNums({1, 2});
        auto ans = Solution().reverseList(head);
        auto rightAns = GenLinksByNums({2, 1});
        ASSERT_TRUE(isSameList(rightAns, ans));
    }

    TEST(reverseListTest, MyTest0) {
        auto head = GenLinksByNums({});
        auto ans = Solution().reverseList(head);
        auto rightAns = GenLinksByNums({});
        ASSERT_TRUE(isSameList(rightAns, ans));
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}