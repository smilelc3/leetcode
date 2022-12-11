//
// Created by smile on 2021/3/16.
//

#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H


# include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

namespace LinkedList {
    // 通过vector<int>构建LinkedList
    ListNode *createByNums(const std::vector<int> &nums);

    // 销毁LinkedList，释放空间
    void destroy(ListNode *head);

    // 判断LinkedList是否相等
    bool isEqual(ListNode const *head1, ListNode const *head2);

    // 判断LinkedList是否存在环
    bool isHasCycle(ListNode const *head);
}


#endif //LEETCODE_LISTNODE_H
