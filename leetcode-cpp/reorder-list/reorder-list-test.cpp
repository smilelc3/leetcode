//
// Created by smile on 2021/4/29.
//

#include <gtest/gtest.h>
#include "reorder-list.cpp"

namespace {
    TEST(reorderListTest, Example1) {       // NOLINT
        auto head = LinkedList::createByNums({1, 2, 3, 4});
        Solution().reorderList(head);
        auto rightAns = LinkedList::createByNums({1, 4, 2, 3});
        ASSERT_TRUE(LinkedList::isEqual(rightAns, head));
        LinkedList::destroy(head);
        LinkedList::destroy(rightAns);
    }

    TEST(reorderListTest, Example2) {       // NOLINT
        auto head = LinkedList::createByNums({1, 2, 3, 4, 5});
        Solution().reorderList(head);
        auto rightAns = LinkedList::createByNums({1, 5, 2, 4, 3});
        ASSERT_TRUE(LinkedList::isEqual(rightAns, head));
        LinkedList::destroy(head);
        LinkedList::destroy(rightAns);
    }

    TEST(reorderListTest, MyTest0) {        // NOLINT
        auto head = LinkedList::createByNums({1, 2, 3, 4, 5, 6, 7, 8});
        Solution().reorderList(head);
        auto rightAns = LinkedList::createByNums({1, 8, 2, 7, 3, 6, 4, 5});
        ASSERT_TRUE(LinkedList::isEqual(rightAns, head));
        LinkedList::destroy(head);
        LinkedList::destroy(rightAns);
    }

    TEST(reorderListTest, Test0) {          // NOLINT
        auto head = LinkedList::createByNums({1});
        Solution().reorderList(head);
        auto rightAns = LinkedList::createByNums({1});
        ASSERT_TRUE(LinkedList::isEqual(rightAns, head));
        LinkedList::destroy(head);
        LinkedList::destroy(rightAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}