//
// Created by smile on 2021/4/13.
//

#include <gtest/gtest.h>
#include <vector>
#include "convert-sorted-list-to-binary-search-tree.cpp"


namespace {
    const int null = -1;
    TEST(sortedListToBSTTest, Example1) {       // NOLINT
        auto head = LinkedList::createByNums({-10, -3, 0, 5, 9});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns1 = BinaryTree::createByNums({0, -3, 9, -10, null, 5}, null);
        auto rightAns2 = BinaryTree::createByNums({0, -3, 9, -10, null, 5}, null);
        ASSERT_TRUE(BinaryTree::isEqual(ans, rightAns1) or BinaryTree::isEqual(ans, rightAns2));
        LinkedList::destroy(head);
        BinaryTree::destroy(ans);
        BinaryTree::destroy(rightAns1);
        BinaryTree::destroy(rightAns2);
    }

    TEST(sortedListToBSTTest, Example2) {       // NOLINT
        auto head = LinkedList::createByNums({});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns = BinaryTree::createByNums({});
        ASSERT_TRUE(BinaryTree::isEqual(ans, rightAns));
        LinkedList::destroy(head);
        BinaryTree::destroy(ans);
        BinaryTree::destroy(rightAns);
    }

    TEST(sortedListToBSTTest, Example3) {       // NOLINT
        auto head = LinkedList::createByNums({0});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns = BinaryTree::createByNums({0});
        ASSERT_TRUE(BinaryTree::isEqual(ans, rightAns));
        LinkedList::destroy(head);
        BinaryTree::destroy(ans);
        BinaryTree::destroy(rightAns);
    }

    TEST(sortedListToBSTTest, Example4) {       // NOLINT
        auto head = LinkedList::createByNums({1, 3});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns = BinaryTree::createByNums({3, 1});
        ASSERT_TRUE(BinaryTree::isEqual(ans, rightAns));
        LinkedList::destroy(head);
        BinaryTree::destroy(ans);
        BinaryTree::destroy(rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
