//
// Created by l30014168 on 2021/7/30.
//

#include <uthash.h>
#include "TreeNode.h"

//
// Created by l30014168 on 2021/7/30.
//


typedef struct tagParentNodeMap {
    int nodeVal;
    struct TreeNode *parent;
    UT_hash_handle hh;
} ParentNodeMap;


static void freeParentNodeMap(ParentNodeMap *head) {
    ParentNodeMap *cur, *tmp;
    HASH_ITER(hh, head, cur, tmp) {
        HASH_DEL(head, cur);                  // delete it
        free(cur);                            // free it
    }
    free(head);
}

int *appendNum(int *ret, int *returnSize, int val) {
    (*returnSize)++;
    if ((*returnSize & (*returnSize -1)) == 0) {
        ret = realloc(ret, (*returnSize) * 2 * sizeof(int));
    }
    ret[*returnSize -1] = val;
    return ret;
}

// 更新所有父节点Map
ParentNodeMap * updateNodeParent(struct TreeNode *root, ParentNodeMap *mapHead) {
    if (root->left != NULL) {
        // 节点值不重复，不再判断重复
        ParentNodeMap *item = malloc(sizeof(ParentNodeMap));
        item->nodeVal = root->left->val;
        item->parent = root;
        HASH_ADD_INT(mapHead, nodeVal, item);
        updateNodeParent(root->left, mapHead);
    }
    if (root->right != NULL) {
        // 节点值不重复，不再判断重复
        ParentNodeMap *item = malloc(sizeof(ParentNodeMap));
        item->nodeVal = root->right->val;
        item->parent = root;
        HASH_ADD_INT(mapHead, nodeVal, item);
        updateNodeParent(root->right, mapHead);
    }
    return mapHead;
}


// 从某个节点向下查找距离K
void childDistanceK(struct TreeNode *root, int k, int **ret, int *returnSize) {
    if (root == NULL) {
        return;
    }
    if (k == 0) {
        *ret = appendNum(*ret, returnSize, root->val);
        return;
    }
    if (root->left != NULL) {
        childDistanceK(root->left, k - 1, ret, returnSize);
    }
    if (root->right != NULL) {
        childDistanceK(root->right, k - 1, ret, returnSize);
    }
}


int *distanceK(struct TreeNode *root, struct TreeNode *target, int k, int *returnSize) {
    if (root == NULL) {
        return NULL;
    }
    ParentNodeMap *parentNodeMap = NULL;
    parentNodeMap = updateNodeParent(root, parentNodeMap);

    int *ret = NULL;
    *returnSize = 0;

    // 从target节点往下走
    childDistanceK(target, k, &ret, returnSize);

    // 从父结点扩展
    ParentNodeMap *find = NULL;
    while (k >= 0) {
        HASH_FIND_INT(parentNodeMap, &target->val, find);
        if (find == NULL) {     // target = root已找完
            break;
        }
        k--;
        if (k == 0) {
            ret = appendNum(ret, returnSize, find->parent->val);
        } else {
            if (find->parent->left == target) {
                childDistanceK(find->parent->right, k - 1, &ret, returnSize);
            } else {
                childDistanceK(find->parent->left, k - 1, &ret, returnSize);
            }
        }
        target = find->parent;
    }
    freeParentNodeMap(parentNodeMap);
    return ret;
}