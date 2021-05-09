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
        // BFS method
        // return BFSConnect(root);

        // DFS method
        DFSConnect(root);
        return root;
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
                if (pNode->left != nullptr) {   // 满二叉树，只需要判断左右其中一个
                    nodesQueue.emplace(pNode->left);
                    nodesQueue.emplace(pNode->right);
                }
            }
        }
        return root;
    }


    void DFSConnect(Node *root) {
        if (root == nullptr || root->left == nullptr) {
            return;
        }

        root->left->next = root->right;
        if (root->next != nullptr) {
            root->right->next = root->next->left;   // 父节点在之前的递归中已经建立了next
        }
        connect(root->left);
        connect(root->right);
    }
};