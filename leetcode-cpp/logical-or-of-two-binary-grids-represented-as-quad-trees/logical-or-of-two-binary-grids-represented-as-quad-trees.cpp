//
// Created by smile on 2022/1/3.
//

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }

    ~Node() {
        delete topLeft;
        delete topRight;
        delete bottomLeft;
        delete bottomRight;
    }
};


class Solution {
public:
    Node *intersect(const Node *quadTree1, const Node *quadTree2) {
        // 递归边界是存在叶子节点
        if (quadTree1->isLeaf and quadTree2->isLeaf) {
            return new Node(quadTree1->val or quadTree2->val, true);
        }
        if (quadTree2->isLeaf) {
            std::swap(quadTree1, quadTree2);
        }
        if (quadTree1->isLeaf and not quadTree2->isLeaf) {
            return quadTree1->val ? new Node(true, true) : deepCopyNode(quadTree2);

        }
        // 两个都是非叶子结点
        auto node = new Node(false, false,
                             intersect(quadTree1->topLeft, quadTree2->topLeft),
                             intersect(quadTree1->topRight, quadTree2->topRight),
                             intersect(quadTree1->bottomLeft, quadTree2->bottomLeft),
                             intersect(quadTree1->bottomRight, quadTree2->bottomRight));
        // 合并可能四个区块值都为1
        if (node->topLeft->val and node->topRight->val and
            node->bottomLeft->val and node->bottomRight->val and
            node->topLeft->isLeaf and node->topRight->isLeaf and
            node->bottomLeft->isLeaf and node->bottomRight->isLeaf) {
            delete node->topLeft;
            delete node->topRight;
            delete node->bottomLeft;
            delete node->bottomRight;
            node->topLeft = node->topRight = node->bottomLeft = node->bottomRight = nullptr;
            node->isLeaf = true;
            node->val = true;
        }
        return node;
    }

private:
    Node *deepCopyNode(const Node *quadTree) {
        if (quadTree == nullptr) {
            return nullptr;
        }
        return new Node(
                quadTree->val, quadTree->isLeaf,
                deepCopyNode(quadTree->topLeft),
                deepCopyNode(quadTree->topRight),
                deepCopyNode(quadTree->bottomLeft),
                deepCopyNode(quadTree->bottomRight)
        );
    }
};