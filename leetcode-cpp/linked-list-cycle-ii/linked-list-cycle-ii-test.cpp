//
// Created by smile on 2021/4/28.
//

#include <gtest/gtest.h>
#include "linked-list-cycle-ii.cpp"

namespace {
    TEST(detectCycleTest, Example1) {       // NOLINT
        ListNode *head = LinkedListCreateByNums({3, 2, 0, -4});
        head->next->next->next->next = head->next;
        auto ans = Solution().detectCycle(head);
        ASSERT_EQ(ans, head->next);
        head->next->next->next->next = nullptr;
        LinkedListDestroy(head);
    }

    TEST(hasCycleTest, Example2) {      // NOLINT
        ListNode *head = LinkedListCreateByNums({1, 2});
        head->next->next = head;
        auto ans = Solution().detectCycle(head);
        ASSERT_EQ(ans, head);
        head->next->next = nullptr;
        LinkedListDestroy(head);
    }

    TEST(hasCycleTest, Example3) {      // NOLINT
        ListNode *head = LinkedListCreateByNums({1});
        auto ans = Solution().detectCycle(head);
        ASSERT_EQ(ans, nullptr);
        LinkedListDestroy(head);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
