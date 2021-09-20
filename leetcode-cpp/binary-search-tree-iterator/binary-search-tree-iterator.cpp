//
// Created by smile on 2021/9/20.
//

#include <stack>
#include "TreeNode.h"

class BSTIterator {
public:
    explicit BSTIterator(TreeNode *root) {
        this->root = root;
    }

    int next() {
        return 0;
    }

    bool hasNext() {
        return false;
    }

    void printInorder() {
        // 中序遍历： 左 -> 中 -> 右
        auto pNode = root;
        stack.emplace(pNode);
        while (not stack.empty()) {
            TreeNode *tmp = stack.top();
            stack.pop();

            if (tmp != nullptr) {
                std::cout << tmp->val << " ";
                stack.emplace(tmp->right);
                stack.emplace(tmp->left);
            }

        }
    }

private:
    TreeNode *root;
    std::stack<TreeNode *> stack;       // 树节点栈
};