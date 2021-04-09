//
// Created by smile on 2021/3/14.
//

#ifndef LEETCODE_CPP_TREENODE_H
#define LEETCODE_CPP_TREENODE_H

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}

    explicit TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};


// 通过vector<int>构建Tree
TreeNode *GenTreeByNums(std::vector<int> &nums, int nullNum);

#endif //LEETCODE_CPP_TREENODE_H
