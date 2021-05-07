//
// Created by smile on 2021/5/7.
//

#include <ListNode.h>
#include <vector>
#include <algorithm>

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        //return insertMethod(head);

        return STLSortMethod(head);
    }

private:
    // time: O(n^2) space:O(1)
    ListNode *insertMethod(ListNode *head) {
        // 单链表插入排序
        auto preNode = head;
        for (auto node = head->next; node != nullptr;) {
            auto nextNode = node->next;
            // node 为待插入的数据，nextNode为保存的下一次访问节点
            if (node->val < head->val) {
                preNode->next = node->next;
                node->next = head;
                head = node;
            } else {
                auto contrNode = head->next;
                auto preContrNode = head;
                while (contrNode->val <= node->val and contrNode != node) {
                    contrNode = contrNode->next;
                    preContrNode = preContrNode->next;
                }
                if (contrNode != node) {
                    preNode->next = node->next;
                    preContrNode->next = node;
                    node->next = contrNode;
                }
            }
            if (preNode->next != nextNode) {
                preNode = preNode->next;
            }
            node = nextNode;
        }
        return head;
    }

    // time: O(nlog(n)) space:O(n)
    ListNode *STLSortMethod(ListNode *head) {
        std::vector<decltype(ListNode::val)> temp;
        auto node = head;
        while (node != nullptr) {
            temp.emplace_back(node->val);
            node = node->next;
        }
        std::sort(temp.begin(), temp.end());

        node = head;
        auto idx = 0;
        while (node != nullptr) {
            node->val = temp[idx++];
            node = node->next;
        }
        return head;
    }
};