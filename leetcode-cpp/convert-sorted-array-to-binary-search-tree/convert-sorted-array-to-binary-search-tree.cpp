//
// Created by smile on 2021/4/12.
//
#include <vector>
#include "TreeNode.h"

class Solution {
public:
    TreeNode *sortedArrayToBST(const std::vector<int> &nums) {
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