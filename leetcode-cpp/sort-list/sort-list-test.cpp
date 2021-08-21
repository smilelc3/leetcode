//
// Created by smile on 2021/4/9.
//
#include <gtest/gtest.h>
#include <vector>

#include "sort-list.cpp"

namespace {
    TEST(sortListTest, Example1) {      // NOLINT
        auto head = LinkedListCreateByNums({4, 2, 3, 1});
        auto ans = Solution::sortList(head);
        auto rightAns = LinkedListCreateByNums({1, 2, 3, 4});
        ASSERT_TRUE(isSameLinkedList(rightAns, ans));
        LinkedListDestroy(ans);
        LinkedListDestroy(rightAns);
    }

    TEST(sortListTest, Example2) {      // NOLINT
        auto head = LinkedListCreateByNums({-1, 5, 3, 4, 0});
        auto ans = Solution::sortList(head);
        auto rightAns = LinkedListCreateByNums({-1, 0, 3, 4, 5});
        ASSERT_TRUE(isSameLinkedList(rightAns, ans));
        LinkedListDestroy(ans);
        LinkedListDestroy(rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}