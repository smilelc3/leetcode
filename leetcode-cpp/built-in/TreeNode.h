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
TreeNode *TreeCreateByNums(const std::vector<int> &nums, int nullNum);
TreeNode *TreeCreateByNums(const std::vector<int> &nums);

// 回收Tree
void TreeDestroy(TreeNode *root);

// 通过判断两棵树是否相等
bool isSameTree(TreeNode const *root1, TreeNode const *root2);

#endif //LEETCODE_CPP_TREENODE_H
