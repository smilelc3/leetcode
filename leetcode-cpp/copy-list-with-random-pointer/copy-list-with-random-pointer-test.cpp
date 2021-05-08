//
// Created by smile on 2021/5/8.
//

#include <gtest/gtest.h>
#include <vector>
#include "copy-list-with-random-pointer.cpp"

namespace {
    TEST(copyRandomListTest, Example1) { //NOLINT
        auto head = Node(7);
        auto Node1 = Node(13);
        auto Node2 = Node(11);
        auto Node3 = Node(10);
        auto Node4 = Node(1);

        head.next = &Node1;
        Node1.next = &Node2;
        Node2.next = &Node3;
        Node3.next = &Node4;

        Node1.random = &head;
        Node3.random = &Node2;
        Node4.random = &head;

        auto pHeadCopy = Solution().copyRandomList(&head);

        ASSERT_EQ(pHeadCopy->val, 7);
        ASSERT_EQ(pHeadCopy->next->val, 13);
        ASSERT_EQ(pHeadCopy->next->next->val, 11);
        ASSERT_EQ(pHeadCopy->next->next->next->val, 10);
        ASSERT_EQ(pHeadCopy->next->next->next->next->val, 1);
        ASSERT_EQ(pHeadCopy->next->next->next->next->next, nullptr);

        ASSERT_EQ(pHeadCopy->random, nullptr);
        ASSERT_EQ(pHeadCopy->next->random, pHeadCopy);
        ASSERT_EQ(pHeadCopy->next->next->random, nullptr);
        ASSERT_EQ(pHeadCopy->next->next->next->random, pHeadCopy->next->next);
        ASSERT_EQ(pHeadCopy->next->next->next->next->random, pHeadCopy);
    }

    TEST(copyRandomListTest, Example2) { // NOLINT
        auto head = Node(1);
        auto Node1 = Node(2);

        head.next = &Node1;

        head.random = &Node1;
        Node1.random = &Node1;

        auto pHeadCopy = Solution().copyRandomList(&head);

        ASSERT_EQ(pHeadCopy->val, 1);
        ASSERT_EQ(pHeadCopy->next->val, 2);
        ASSERT_EQ(pHeadCopy->next->next, nullptr);

        ASSERT_EQ(pHeadCopy->random, pHeadCopy->next);
        ASSERT_EQ(pHeadCopy->next->random, pHeadCopy->next);
    }

    TEST(copyRandomListTest, Example3) { // NOLINT
        auto head = Node(3);
        auto Node1 = Node(3);
        auto Node2 = Node(3);

        head.next = &Node1;
        Node1.next = &Node2;

        Node1.random = &head;

        auto pHeadCopy = Solution().copyRandomList(&head);

        ASSERT_EQ(pHeadCopy->val, 3);
        ASSERT_EQ(pHeadCopy->next->val, 3);
        ASSERT_EQ(pHeadCopy->next->next->val, 3);
        ASSERT_EQ(pHeadCopy->next->next->next, nullptr);

        ASSERT_EQ(pHeadCopy->random, nullptr);
        ASSERT_EQ(pHeadCopy->next->random, pHeadCopy);
        ASSERT_EQ(pHeadCopy->next->next->random, nullptr);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}