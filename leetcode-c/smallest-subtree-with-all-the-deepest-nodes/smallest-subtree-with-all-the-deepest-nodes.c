//
// Created by l30014168 on 2021/12/2.
//

#include "util.h"

// 返回root节点的到最深子节点的距离
size_t dfsFind(struct TreeNode *root, size_t curDeep, struct TreeNode **pAns, size_t *pDeepest) {
    if (root == NULL) {
        return 0;
    }
    size_t leftDisToDeepest = dfsFind(root->left, curDeep + 1, pAns, pDeepest);
    size_t rightDisToDeepest = dfsFind(root->right, curDeep + 1, pAns, pDeepest);
    if (leftDisToDeepest == rightDisToDeepest && leftDisToDeepest + curDeep >= *pDeepest) {
        *pDeepest = leftDisToDeepest + curDeep,
        *pAns = root;
    }

    return max(leftDisToDeepest, rightDisToDeepest) + 1;
}

struct TreeNode *subtreeWithAllDeepest(struct TreeNode *root) {
    size_t deepest = 0;
    struct TreeNode *ans = NULL;

    dfsFind(root, 0, &ans, &deepest);
    return ans;
}