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
    Vector *str = VectorCreate(sizeof(char));
    char tmp = '[';
    VectorAppend(str, &tmp);

    if (root != NULL) {
        Vector *preLevelTreeNodes = VectorCreate(sizeof(struct TreeNode *));
        VectorAppend(preLevelTreeNodes, &root);
        while (!VectorIsEmpty(preLevelTreeNodes)) {

        }
        VectorDestroy(preLevelTreeNodes);
    }

    tmp = ']';
    VectorAppend(str, &tmp);
    char *ret = malloc(str->size * str->itemSize);
    memcpy(ret, str->items, str->size * str->itemSize);
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
    int nullNum = -1;

    for (size_t idx = 1; idx <= length - 2; ++idx) {
        if (data[idx] == ',') {
            int num;
            if (idx - left == 4 &&
                data[left] == 'n' && data[left + 1] == 'u' && data[left + 2] == 'l' && data[left + 3] == 'l') {
                num = -1;
            } else {
                num = str2Int(data + left, idx - left);
            }
            if (VectorAppend(nums, &num) != 0) {
                VectorDestroy(nums);
                return NULL;
            }
            left = idx + 1;
        }
    }
    for (int idx = 0; idx < nums->size; ++idx) {
        printf("%d", *(int *) VectorAt(nums, idx));
    }

    // step 2: TreeCreateByNums
    struct TreeNode *ret = TreeCreateByNums(nums->items, nums->size, nullNum);
    VectorDestroy(nums);
    return ret;
}
