//
// Created by smile on 2021/8/22.
//

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "TreeNode.h"
#include "Vector.h"

// 字符串转数字
int str2Int(const char *str, size_t length) {
    if (length == 0) {
        return 0;
    }
    if (str[0] == '-') {
        return -str2Int(str + 1, length - 1);
    }
    int ret = 0;
    for (size_t idx = 0; idx < length; ++idx) {
        if (!isdigit(str[idx])) {
            break;
        }
        ret *= 10;
        ret += str[idx] - '0';
    }
    return ret;
}


/** Encodes a tree to a single string. */
char *serialize(struct TreeNode *root) {
    Vector *nums = VectorCreate(sizeof(int));
    int nullNum = INT_MIN;
    if (root != NULL) {
        Vector *preLevelTreeNodes = VectorCreate(sizeof(struct TreeNode *));
        VectorAppend(preLevelTreeNodes, &root);
        VectorAppend(nums, &root->val);
        while (!VectorIsEmpty(preLevelTreeNodes)) {
            size_t numPreLevelNodes = preLevelTreeNodes->size;
            struct TreeNode **pPreLevelNode;
            for (size_t idx = 0; idx < numPreLevelNodes; idx++) {
                // 左子树
                pPreLevelNode = VectorAtNoCheck(preLevelTreeNodes, idx);
                if ((*pPreLevelNode)->left != NULL) {
                    VectorAppend(nums, &(*pPreLevelNode)->left->val);
                    VectorAppend(preLevelTreeNodes, &(*pPreLevelNode)->left);
                } else {
                    VectorAppend(nums, &nullNum);
                }
                // 右子树
                pPreLevelNode = VectorAtNoCheck(preLevelTreeNodes, idx);
                if ((*pPreLevelNode)->right != NULL) {
                    VectorAppend(nums, &(*pPreLevelNode)->right->val);
                    VectorAppend(preLevelTreeNodes, &(*pPreLevelNode)->right);
                } else {
                    VectorAppend(nums, &nullNum);
                }
            }
            VectorErase(preLevelTreeNodes, 0, numPreLevelNodes);
        }
        VectorDestroy(preLevelTreeNodes);
    }

    // 去除末尾nullNum
    while (nums->size > 0 && *(int *) VectorAt(nums, nums->size - 1) == nullNum) {
        nums->size--;
    }

    Vector *str = VectorCreate(sizeof(char));
    char tmp = '[';
    VectorAppend(str, &tmp);

    char buf[11];
    for (size_t idx = 0; idx < nums->size; ++idx) {
        int num = *(int *) VectorAtNoCheck(nums, idx);
        if (num != nullNum) {
            sprintf(buf, "%d", num);
        } else {
            strcpy(buf, "null");
        }
        for (size_t strIdx = 0; strIdx < strlen(buf); strIdx++) {
            VectorAppend(str, &buf[strIdx]);
        }
        if (idx != nums->size - 1) {
            tmp = ',';
            VectorAppend(str, &tmp);
        }
    }

    tmp = ']';
    VectorAppend(str, &tmp);
    VectorDestroy(nums);

    char *ret = malloc(str->size * str->itemSize + 1);
    memcpy(ret, str->items, str->size * str->itemSize);
    ret[str->size * str->itemSize] = '\0';
    VectorDestroy(str);

    return ret;
}

/** Decodes your encoded data to tree. */
struct TreeNode *deserialize(char *data) {
    // first step: transform char* to int*
    size_t length = strlen(data);
    if (length <= 2) {
        return NULL;
    }
    Vector *nums = VectorCreate(sizeof(int));
    if (nums == NULL) {
        perror("VectorCreate fail.\n");
        return NULL;
    }

    size_t left = 1;
    int nullNum = INT_MIN;

    int num;
    for (size_t idx = 1; idx <= length - 2; ++idx) {
        if (data[idx] == ',') {
            if (idx - left == 4 &&
                data[left] == 'n' && data[left + 1] == 'u' && data[left + 2] == 'l' && data[left + 3] == 'l') {
                num = nullNum;
            } else {
                num = str2Int(data + left, idx - left);
            }
            VectorAppend(nums, &num);
            left = idx + 1;
        }
    }
    // 最后一个单独处理
    num = str2Int(data + left, length - left - 1);
    VectorAppend(nums, &num);

    // step 2: TreeCreateByNums
    struct TreeNode *ret = TreeCreateByNums(nums->items, nums->size, nullNum);
    VectorDestroy(nums);
    return ret;
}
