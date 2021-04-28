//
// Created by smile on 2021/4/28.
//

#include <gtest/gtest.h>
#include "clone-graph.cpp"

namespace {
    TEST(cloneGraphTest, Example1) {
        auto node1 = new Node(1);
        auto node2 = new Node(2);
        auto node3 = new Node(3);
        auto node4 = new Node(4);

        node1->neighbors = {node2, node4};
        node2->neighbors = {node1, node3};
        node3->neighbors = {node2, node4};
        node4->neighbors = {node1, node3};

        auto node1Copy = Solution().cloneGraph(node1);
        ASSERT_EQ(node1Copy->val, 1);
        ASSERT_EQ(node1Copy->neighbors.size(), 2);

        auto node2Copy = node1Copy->neighbors[0];
        ASSERT_EQ(node2Copy->val, 2);
        ASSERT_EQ(node2Copy->neighbors.size(), 2);

        auto node4Copy = node1Copy->neighbors[1];
        ASSERT_EQ(node4Copy->val, 4);
        ASSERT_EQ(node4Copy->neighbors.size(), 2);

        auto node3Copy = node2Copy->neighbors[1];
        ASSERT_EQ(node3Copy->val, 3);
        ASSERT_EQ(node3Copy->neighbors.size(), 2);

        ASSERT_EQ(node1Copy->neighbors[0], node2Copy);
        ASSERT_EQ(node1Copy->neighbors[1], node4Copy);
        ASSERT_EQ(node2Copy->neighbors[0], node1Copy);
        ASSERT_EQ(node2Copy->neighbors[1], node3Copy);
        ASSERT_EQ(node3Copy->neighbors[0], node2Copy);
        ASSERT_EQ(node3Copy->neighbors[1], node4Copy);
        ASSERT_EQ(node4Copy->neighbors[0], node1Copy);
        ASSERT_EQ(node4Copy->neighbors[1], node3Copy);

        ASSERT_NE(node1, node1Copy);
        ASSERT_NE(node2, node2Copy);
        ASSERT_NE(node3, node3Copy);
        ASSERT_NE(node4, node4Copy);
    }

    TEST(cloneGraphTest, Example2) {
        auto node1 = new Node(1);
        auto node1Copy = Solution().cloneGraph(node1);
        ASSERT_EQ(node1Copy->val, 1);
        ASSERT_EQ(node1Copy->neighbors.size(), 0);

        ASSERT_NE(node1, node1Copy);
    }

    TEST(cloneGraphTest, Example3) {
        Node *node = nullptr;
        auto nodeCopy = Solution().cloneGraph(node);
        ASSERT_EQ(nodeCopy, nullptr);
    }

    TEST(cloneGraphTest, Example4) {
        auto node1 = new Node(1);
        auto node2 = new Node(2);
        node1->neighbors = {node2};
        node2->neighbors = {node1};

        auto node1Copy = Solution().cloneGraph(node1);
        ASSERT_EQ(node1Copy->val, 1);
        ASSERT_EQ(node1Copy->neighbors.size(), 1);

        auto node2Copy = node1Copy->neighbors[0];
        ASSERT_EQ(node2Copy->val, 2);
        ASSERT_EQ(node2Copy->neighbors.size(), 1);

        ASSERT_EQ(node1Copy->neighbors[0], node2Copy);
        ASSERT_EQ(node2Copy->neighbors[0], node1Copy);
        ASSERT_NE(node1, node1Copy);
        ASSERT_NE(node2, node2Copy);

    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}