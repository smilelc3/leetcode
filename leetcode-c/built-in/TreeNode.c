//
// Created by l30014168 on 2021/7/13.
//

#include <stdlib.h>
#include "TreeNode.h"

// 删除树
void TreeDestroy(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    TreeDestroy(root->left);
    TreeDestroy(root->right);
    free(root);
}
