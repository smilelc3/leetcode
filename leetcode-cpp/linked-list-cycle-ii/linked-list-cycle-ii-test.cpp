//
// Created by smile on 2021/4/28.
//

#include <gtest/gtest.h>
#include <vector>
#include "linked-list-cycle-ii.cpp"

namespace {
    TEST(detectCycleTest, Example1) {
        ListNode *head = GenLinksByNums(std::vector<int>{3, 2, 0, -4});
        head->next->next->next->next = head->next;
        auto ans = Solution().detectCycle(head);
        ASSERT_EQ(ans, head->next);
    }

    TEST(hasCycleTest, Example2) {
        ListNode *head = GenLinksByNums(std::vector<int>{1, 2});
        head->next->next = head;
        auto ans = Solution().detectCycle(head);
        ASSERT_EQ(ans, head);
    }

    TEST(hasCycleTest, Example3) {
        ListNode *head = GenLinksByNums(std::vector<int>{1});
        auto ans = Solution().detectCycle(head);
        ASSERT_EQ(ans, nullptr);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
