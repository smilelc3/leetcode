#include <gtest/gtest.h>
#include <vector>
#include "linked-list-cycle.cpp"

namespace {
    TEST(hasCycleTest, Example1) {
        auto nums = std::vector<int>{3, 2, 0, -4};
        ListNode *head = GenLinksByNums(nums);
        head->next->next->next->next = head->next;
        bool ans = Solution::hasCycle(head);
        ASSERT_TRUE(ans);
    }


    TEST(hasCycleTest, Example2) {
        auto nums = std::vector<int>{1, 2};
        ListNode *head = GenLinksByNums(nums);
        head->next->next = head;
        bool ans = Solution::hasCycle(head);
        ASSERT_TRUE(ans);
    }

    TEST(hasCycleTest, Example3) {
        auto nums = std::vector<int>{1};
        ListNode *head = GenLinksByNums(nums);
        bool ans = Solution::hasCycle(head);
        ASSERT_FALSE(ans);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
