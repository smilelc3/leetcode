//
// Created by smile on 2022/12/11.
//

#include <gtest/gtest.h>
#include <vector>
#include "ListNode.h"
#include "split-linked-list-in-parts.cpp"

namespace {
    TEST(splitListToPartsTest, Example1) {    // NOLINT
        auto root = LinkedList::createByNums({1, 2, 3});
        int k = 5;
        auto ans = Solution().splitListToParts(root, k);
        decltype(ans) correctAns = {new ListNode(1), new ListNode(2), new ListNode(3), nullptr, nullptr};
        ASSERT_EQ(ans.size(), correctAns.size());
        for (size_t idx = 0; idx < ans.size(); ++idx) {
            ASSERT_TRUE(LinkedList::isEqual(ans[idx], correctAns[idx]));
        }
        LinkedList::destroy(root);
        auto destroyList = [](ListNode *head) { LinkedList::destroy(head); };
        std::for_each(ans.begin(), ans.end(), destroyList);
        std::for_each(correctAns.begin(), correctAns.end(), destroyList);
    }

    TEST(splitListToPartsTest, Example2) {    // NOLINT
        auto root = LinkedList::createByNums({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        int k = 3;
        auto ans = Solution().splitListToParts(root, k);
        decltype(ans) correctAns = {LinkedList::createByNums({1, 2, 3, 4}),
                                    LinkedList::createByNums({5, 6, 7}),
                                    LinkedList::createByNums({8, 9, 10})};
        ASSERT_EQ(ans.size(), correctAns.size());
        for (size_t idx = 0; idx < ans.size(); ++idx) {
            ASSERT_TRUE(LinkedList::isEqual(ans[idx], correctAns[idx]));
        }
        LinkedList::destroy(root);
        auto destroyList = [](ListNode *head) { LinkedList::destroy(head); };
        std::for_each(ans.begin(), ans.end(), destroyList);
        std::for_each(correctAns.begin(), correctAns.end(), destroyList);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}