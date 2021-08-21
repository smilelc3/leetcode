//
// Created by smile on 2021/4/29.
//


#include <gtest/gtest.h>
#include "reverse-linked-list.cpp"

namespace {
    TEST(reverseListTest, Example1) {       // NOLINT
        auto head = LinkedListCreateByNums({1, 2, 3, 4, 5});
        auto ans = Solution().reverseList(head);
        auto rightAns = LinkedListCreateByNums({5, 4, 3, 2, 1});
        ASSERT_TRUE(isSameLinkedList(rightAns, ans));
        LinkedListDestroy(ans);
        LinkedListDestroy(rightAns);
    }

    TEST(reverseListTest, Example2) {       // NOLINT
        auto head = LinkedListCreateByNums({1, 2});
        auto ans = Solution().reverseList(head);
        auto rightAns = LinkedListCreateByNums({2, 1});
        ASSERT_TRUE(isSameLinkedList(rightAns, ans));
        LinkedListDestroy(ans);
        LinkedListDestroy(rightAns);
    }

    TEST(reverseListTest, MyTest0) {        // NOLINT
        auto head = LinkedListCreateByNums({});
        auto ans = Solution().reverseList(head);
        auto rightAns = LinkedListCreateByNums({});
        ASSERT_TRUE(isSameLinkedList(rightAns, ans));
        LinkedListDestroy(ans);
        LinkedListDestroy(rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}