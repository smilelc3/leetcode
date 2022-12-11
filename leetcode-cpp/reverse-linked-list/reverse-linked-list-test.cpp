//
// Created by smile on 2021/4/29.
//


#include <gtest/gtest.h>
#include "reverse-linked-list.cpp"

namespace {
    TEST(reverseListTest, Example1) {       // NOLINT
        auto head = LinkedList::createByNums({1, 2, 3, 4, 5});
        auto ans = Solution().reverseList(head);
        auto rightAns = LinkedList::createByNums({5, 4, 3, 2, 1});
        ASSERT_TRUE(LinkedList::isEqual(rightAns, ans));
        LinkedList::destroy(ans);
        LinkedList::destroy(rightAns);
    }

    TEST(reverseListTest, Example2) {       // NOLINT
        auto head = LinkedList::createByNums({1, 2});
        auto ans = Solution().reverseList(head);
        auto rightAns = LinkedList::createByNums({2, 1});
        ASSERT_TRUE(LinkedList::isEqual(rightAns, ans));
        LinkedList::destroy(ans);
        LinkedList::destroy(rightAns);
    }

    TEST(reverseListTest, MyTest0) {        // NOLINT
        auto head = LinkedList::createByNums({});
        auto ans = Solution().reverseList(head);
        auto rightAns = LinkedList::createByNums({});
        ASSERT_TRUE(LinkedList::isEqual(rightAns, ans));
        LinkedList::destroy(ans);
        LinkedList::destroy(rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}