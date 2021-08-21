#include <gtest/gtest.h>
#include <vector>
#include "linked-list-cycle.cpp"

namespace {
    TEST(hasCycleTest, Example1) {      // NOLINT
        auto nums = std::vector<int>{3, 2, 0, -4};
        ListNode *head = LinkedListCreateByNums(nums);
        head->next->next->next->next = head->next;
        bool ans = Solution::hasCycle(head);
        ASSERT_TRUE(ans);
        head->next->next->next->next = nullptr;
        LinkedListDestroy(head);
    }


    TEST(hasCycleTest, Example2) {      // NOLINT
        auto nums = std::vector<int>{1, 2};
        ListNode *head = LinkedListCreateByNums(nums);
        head->next->next = head;
        bool ans = Solution::hasCycle(head);
        ASSERT_TRUE(ans);
        head->next->next = nullptr;
        LinkedListDestroy(head);
    }

    TEST(hasCycleTest, Example3) {      // NOLINT
        auto nums = std::vector<int>{1};
        ListNode *head = LinkedListCreateByNums(nums);
        bool ans = Solution::hasCycle(head);
        ASSERT_FALSE(ans);
        LinkedListDestroy(head);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
