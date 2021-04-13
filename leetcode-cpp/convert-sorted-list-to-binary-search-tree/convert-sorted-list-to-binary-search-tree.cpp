//
// Created by smile on 2021/4/13.
//

#include <vector>
#include "ListNode.h"
#include "TreeNode.h"


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> nums;
        auto pNode = head;
        while (pNode != nullptr) {
            nums.emplace_back(pNode->val);
            pNode = pNode->next;
        }
        return sortedArrayToBSTByIter(nums.begin(), nums.end());
    }

private:
    TreeNode *sortedArrayToBSTByIter(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
        if (begin == end) {
            return nullptr;
        }
        if (end - begin == 1) {
            return new TreeNode(*begin);
        }
        auto mid = begin + (end - begin) / 2;
        auto root = new TreeNode(*mid);
        root->left = sortedArrayToBSTByIter(begin, mid);
        root->right = sortedArrayToBSTByIter(mid + 1, end);
        return root;
    }
};