//
// Created by smile on 2021/4/29.
//

#include <gtest/gtest.h>
#include "reorder-list.cpp"

namespace {
    TEST(reorderListTest, Example1) {
        auto head = GenLinksByNums({1, 2, 3, 4});
        Solution().reorderList(head);
        auto rightAns = GenLinksByNums({1, 4, 2, 3});
        ASSERT_TRUE(isSameList(rightAns, head));
    }

    TEST(reorderListTest, Example2) {
        auto head = GenLinksByNums({1, 2, 3, 4, 5});
        Solution().reorderList(head);
        auto rightAns = GenLinksByNums({1, 4, 2, 3, 5});
        ASSERT_TRUE(isSameList(rightAns, head));
    }

    TEST(reorderListTest, MyTest0) {
        auto head = GenLinksByNums({1, 2, 3, 4, 5, 6, 7, 8});
        Solution().reorderList(head);
        auto rightAns = GenLinksByNums({1, 8, 2, 7, 3, 6, 4, 5});
        ASSERT_TRUE(isSameList(rightAns, head));
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}