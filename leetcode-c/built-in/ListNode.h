//
// Created by l30014168 on 2021/9/8.
//

#ifndef LEETCODE_C_LISTNODE_H
#define LEETCODE_C_LISTNODE_H

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


// 根据数组创建树
struct ListNode *ListCreateByNums(const int *nums, size_t numsSize);

// 释放二叉树
void ListDestroy(struct ListNode *head);

#endif //LEETCODE_C_LISTNODE_H
