//
// Created by smile on 2021/5/7.
//

#include <gtest/gtest.h>
#include "insertion-sort-list.cpp"

namespace {
    TEST(insertionSortListTest, Example1) {     // NOLINT
        auto head = LinkedListCreateByNums({4, 2, 1, 3});
        auto ans = Solution().insertionSortList(head);
        auto rightAns = LinkedListCreateByNums({1, 2, 3, 4});
        ASSERT_TRUE(isSameLinkedList(ans, rightAns));
        LinkedListDestroy(head);
        LinkedListDestroy(rightAns);
    }

    TEST(insertionSortListTest, Example2) {     // NOLINT
        auto head = LinkedListCreateByNums({-1, 0, 3, 4, 5});
        auto ans = Solution().insertionSortList(head);
        auto rightAns = LinkedListCreateByNums({-1, 0, 3, 4, 5});
        ASSERT_TRUE(isSameLinkedList(ans, rightAns));
        LinkedListDestroy(head);
        LinkedListDestroy(rightAns);
    }

    TEST(insertionSortListTest, Example3) {     // NOLINT
        auto head = LinkedListCreateByNums({-1, 5, 3, 4, 0});
        auto ans = Solution().insertionSortList(head);
        auto rightAns = LinkedListCreateByNums({-1, 0, 3, 4, 5});
        ASSERT_TRUE(isSameLinkedList(ans, rightAns));
        LinkedListDestroy(head);
        LinkedListDestroy(rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
