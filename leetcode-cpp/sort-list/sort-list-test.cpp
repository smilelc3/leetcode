//
// Created by smile on 2021/4/9.
//
#include <gtest/gtest.h>
#include <vector>

#include "sort-list.cpp"

namespace {
    TEST(sortListTest, Example1) {
        auto nums1 = std::vector<int>{4, 2, 3, 1};
        auto nums2 = std::vector<int>{1, 2, 3, 4};
        auto head = GenLinksByNums(nums1);
        auto ans = Solution::sortList(head);
        auto rightAns = GenLinksByNums(nums2);
        ASSERT_TRUE(isSameList(rightAns, ans));
    }


    TEST(sortListTest, Example2) {
        auto nums1 = std::vector<int>{-1, 5, 3, 4, 0};
        auto nums2 = std::vector<int>{-1, 0, 3, 4, 5};
        auto head = GenLinksByNums(nums1);
        auto ans = Solution::sortList(head);
        auto rightAns = GenLinksByNums(nums2);
        ASSERT_TRUE(isSameList(rightAns, ans));
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}