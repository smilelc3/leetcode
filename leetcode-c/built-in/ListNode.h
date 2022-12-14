//
// Created by l30014168 on 2021/9/8.
//

#ifndef LEETCODE_C_LISTNODE_H
#define LEETCODE_C_LISTNODE_H

#include <stdlib.h>
#include <stdbool.h>

// leetcode 预定义的单向链表 (Singly Linked List)
struct ListNode {
    int val;
    struct ListNode *next;
};

// 根据数组创建链表
struct ListNode *LinkedListCreateByNums(const int *nums, size_t numsSize);

// 释放链表
void LinkedListDestroy(struct ListNode *head);

// 判断两链表是否相同
bool LinkedListIsEqual(const struct ListNode *head1, const struct ListNode *head2);

// 双向链表 (Doubly Linked List)
typedef struct tagDuListNode {
    int val;
    struct tagDuListNode *prev, *next;
} DuListNode;

// 创建一个双向循环链表（额外多一个头节点）
DuListNode *DuCirListCreate(void);

// 在某个节点后添加一个新节点
void DuCirListInsert(DuListNode *pNode, int newVal);

// 销毁双向循环链表
void DuCirListDestroy(DuListNode *node);

// 删除某个节点
void DuCirListErase(DuListNode *pNode);

// 双向循环链表判空
bool DuCirListIsEmpty(const DuListNode *head);

#endif //LEETCODE_C_LISTNODE_H
