//
// Created by smile on 2022/7/9.
//

#include <vector>
#include <stack>
#include "TreeNode.h"


class Solution {
public:
    std::vector<int> postorder(Node *root) {
        ans = {};
        // 递归策略
        postorderRecursiveMethod(root);
        // 迭代策略
        // postorderIterMethod(root);
        return ans;

    }

    void postorderRecursiveMethod(const Node *root) {
        if (root == nullptr) {
            return;
        }
        for (const auto &pChild: root->children) {
            postorderRecursiveMethod(pChild);
        }
        ans.emplace_back(root->val);
    }

    void postorderIterMethod(const Node *root) {
        if (root == nullptr) {
            return;
        }
        std::stack<std::pair<const Node *, decltype(Node().children.size())>> stack;
        stack.emplace(std::make_pair(root, 0));
        while (true) {
            auto pNode = stack.top().first;
            auto nChild = stack.top().second;
            if (pNode->children.empty() or nChild == pNode->children.size()) {  // 当前节点无子树 或 已经访问完所有子树
                ans.emplace_back(pNode->val);
                stack.pop();
                if (stack.empty()) {
                    break;
                }
                stack.top().second++;   // 出栈后，更新栈顶下一个子树位置
                continue;
            }
            // 存在子树，优先子树进栈
            stack.emplace(std::make_pair(pNode->children[nChild], 0));
        }
    }


private:
    std::vector<int> ans;
};