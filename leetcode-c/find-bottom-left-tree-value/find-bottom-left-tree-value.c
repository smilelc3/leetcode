//
// Created smile on 2024/1/18.
//

int SolBottomLeftValue(struct TreeNode *root, size_t *height) {
    if (root == NULL) {
        *height = 0;
        return 0;
    }
    size_t leftHeight, rightHeight;
    int leftVal = SolBottomLeftValue(root->left, &leftHeight);
    int rightVal = SolBottomLeftValue(root->right, &rightHeight);
    if (leftHeight >= rightHeight) {    // 左右子树相等，也返回左节点
        *height = leftHeight + 1;
        return leftHeight == 0 ? root->val : leftVal;   // 根节点返回本身，其他返回左节点值
    } else {
        *height = rightHeight + 1;
        return rightVal;
    }
}

int findBottomLeftValue(struct TreeNode *root) {
    size_t rootHeight;
    return SolBottomLeftValue(root, &rootHeight);
}