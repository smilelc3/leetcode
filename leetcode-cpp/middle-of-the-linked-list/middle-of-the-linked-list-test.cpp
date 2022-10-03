//
// Created by smile on 2022/10/3.
//

#include <gtest/gtest.h>
#include "middle-of-the-linked-list.cpp"

namespace {
    TEST(middleNodeTest, Example1) {        // NOLINT
        auto head = LinkedListCreateByNums({1, 2, 3, 4, 5});
        auto ans = Solution::middleNode(head);
        decltype(ans) correctAns = head->next->next;
        ASSERT_EQ(ans, correctAns);
    }

    TEST(middleNodeTest, Example2) {        // NOLINT
        auto head = LinkedListCreateByNums({1, 2, 3, 4, 5, 6});
        auto ans = Solution::middleNode(head);
        decltype(ans) correctAns = head->next->next->next;
        ASSERT_EQ(ans, correctAns);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
