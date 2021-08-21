//
// Created by smile on 2021/4/13.
//

#include <gtest/gtest.h>
#include <vector>
#include "convert-sorted-list-to-binary-search-tree.cpp"

namespace {
    TEST(sortedListToBSTTest, Example1) {       // NOLINT
        auto head = LinkedListCreateByNums({-10, -3, 0, 5, 9});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns1 = TreeCreateByNums({0, -3, 9, -10, -1, 5}, -1);
        auto rightAns2 = TreeCreateByNums({0, -3, 9, -10, -1, 5}, -1);
        ASSERT_TRUE(isSameTree(ans, rightAns1) or isSameTree(ans, rightAns2));
        LinkedListDestroy(head);
        TreeDestroy(ans);
        TreeDestroy(rightAns1);
        TreeDestroy(rightAns2);
    }

    TEST(sortedListToBSTTest, Example2) {       // NOLINT
        auto head = LinkedListCreateByNums({});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns = TreeCreateByNums({});
        ASSERT_TRUE(isSameTree(ans, rightAns));
        LinkedListDestroy(head);
        TreeDestroy(ans);
        TreeDestroy(rightAns);
    }

    TEST(sortedListToBSTTest, Example3) {       // NOLINT
        auto head = LinkedListCreateByNums({0});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns = TreeCreateByNums({0});
        ASSERT_TRUE(isSameTree(ans, rightAns));
        LinkedListDestroy(head);
        TreeDestroy(ans);
        TreeDestroy(rightAns);
    }

    TEST(sortedListToBSTTest, Example4) {       // NOLINT
        auto head = LinkedListCreateByNums({1, 3});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns = TreeCreateByNums({3, 1});
        ASSERT_TRUE(isSameTree(ans, rightAns));
        LinkedListDestroy(head);
        TreeDestroy(ans);
        TreeDestroy(rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
