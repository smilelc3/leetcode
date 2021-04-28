//
// Created by smile on 2021/4/13.
//

#include <gtest/gtest.h>
#include <vector>
#include "convert-sorted-list-to-binary-search-tree.cpp"

namespace {
    TEST(sortedListToBSTTest, Example1) {
        auto head = GenLinksByNums({-10, -3, 0, 5, 9});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns1 = GenTreeByNums({0, -3, 9, -10, -1, 5}, -1);
        auto rightAns2 = GenTreeByNums({0, -3, 9, -10, -1, 5}, -1);
        ASSERT_TRUE(isSameTree(ans, rightAns1) or isSameTree(ans, rightAns2));
    }

    TEST(sortedListToBSTTest, Example2) {
        auto head = GenLinksByNums({});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns = GenTreeByNums({});
        ASSERT_TRUE(isSameTree(ans, rightAns));
    }

    TEST(sortedListToBSTTest, Example3) {
        auto head = GenLinksByNums({0});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns = GenTreeByNums({0});
        ASSERT_TRUE(isSameTree(ans, rightAns));
    }

    TEST(sortedListToBSTTest, Example4) {
        auto head = GenLinksByNums({1, 3});
        auto ans = Solution().sortedListToBST(head);
        auto rightAns = GenTreeByNums({3, 1});
        ASSERT_TRUE(isSameTree(ans, rightAns));
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
