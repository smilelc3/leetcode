//
// Created by smile on 2021/4/9.
//
#include <gtest/gtest.h>
#include <vector>
#include "sort-list.cpp"

namespace {
    TEST(sortListTest, Example1) {      // NOLINT
        auto head = LinkedList::createByNums({4, 2, 3, 1});
        auto ans = Solution::sortList(head);
        auto rightAns = LinkedList::createByNums({1, 2, 3, 4});
        ASSERT_TRUE(LinkedList::isEqual(rightAns, ans));
        LinkedList::destroy(ans);
        LinkedList::destroy(rightAns);
    }

    TEST(sortListTest, Example2) {      // NOLINT
        auto head = LinkedList::createByNums({-1, 5, 3, 4, 0});
        auto ans = Solution::sortList(head);
        auto rightAns = LinkedList::createByNums({-1, 0, 3, 4, 5});
        ASSERT_TRUE(LinkedList::isEqual(rightAns, ans));
        LinkedList::destroy(ans);
        LinkedList::destroy(rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}