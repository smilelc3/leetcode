//
// Created by smile on 2021/9/20.
//

#include <stack>
#include "TreeNode.h"

class BSTIterator {
public:
    explicit BSTIterator(TreeNode *root) {
        this->root = root;
        cur = root;
    }

    int next() {
        while (cur != nullptr) {
            stack.emplace(cur);
            cur = cur->left;
        }
        cur = stack.top();
        stack.pop();
        auto ret = cur->val;
        cur = cur->right;   // 转向
        return ret;
    }

    bool hasNext() {
        return cur != nullptr or not stack.empty();
    }

    void printPreorder() {
        // 先序遍历：中 -> 左 -> 右
        std::stack<TreeNode *> preorderStack;       // 树节点栈
        auto pNode = root;
        while (pNode != nullptr or not preorderStack.empty()) {
            while (pNode != nullptr) {
                std::cout << pNode->val << " ";
                preorderStack.emplace(pNode);
                pNode = pNode->left;
            }
            pNode = preorderStack.top();
            preorderStack.pop();
            pNode = pNode->right;   // 转向
        }
        std::cout << std::endl;
    }

    void printInorder() {
        // 中序遍历：左 -> 中 -> 右
        std::stack<TreeNode *> inorderStack;       // 树节点栈
        auto pNode = root;
        while (pNode != nullptr or not inorderStack.empty()) {
            while (pNode != nullptr) {
                inorderStack.emplace(pNode);
                pNode = pNode->left;
            }
            pNode = inorderStack.top();
            inorderStack.pop();
            std::cout << pNode->val << " ";
            pNode = pNode->right;   // 转向
        }
        std::cout << std::endl;
    }

private:
    TreeNode *root;
    std::stack<TreeNode *> stack;       // 树节点栈
    TreeNode *cur;
};