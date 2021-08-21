//
// Created by smile on 2021/5/9.
//

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    explicit Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

#include <queue>

class Solution {
public:
    Node *connect(Node *root) {
        DFSConnect(root);
        return root;
    }

    void destroyNode(Node *root) {
        if (root == nullptr) {
            return;
        }
        destroyNode(root->left);
        destroyNode(root->right);
        delete root;
    }

private:
    void DFSConnect(Node *root) {
        if (root == nullptr) {
            return;
        }
        if (root->right != nullptr) {
            root->right->next = getRootNextSubTree(root);
        }
        if (root->left != nullptr) {
            root->left->next = root->right != nullptr ? root->right : getRootNextSubTree(root);
        }
        DFSConnect(root->right);    // 重点：优先访问右子树
        DFSConnect(root->left);
    }

    static constexpr Node *getRootNextSubTree(Node *root) {
        auto rootNext = root->next;
        if (rootNext != nullptr) {
            if (rootNext->left == nullptr and rootNext->right == nullptr) {
                return getRootNextSubTree(rootNext);
            }
            return rootNext->left != nullptr ? rootNext->left : rootNext->right;
        }
        return nullptr;
    }

    Node *BFSConnect(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        std::queue<Node *> nodesQueue;
        nodesQueue.emplace(root);

        while (not nodesQueue.empty()) {
            auto queueSize = nodesQueue.size();
            for (auto idx = 0; idx < queueSize; idx++) {
                auto pNode = nodesQueue.front();
                nodesQueue.pop();
                if (idx != queueSize - 1) {
                    pNode->next = nodesQueue.front();
                }
                if (pNode->left != nullptr) {
                    nodesQueue.emplace(pNode->left);
                }
                if (pNode->right != nullptr) {
                    nodesQueue.emplace(pNode->right);
                }
            }
        }
        return root;
    }
};