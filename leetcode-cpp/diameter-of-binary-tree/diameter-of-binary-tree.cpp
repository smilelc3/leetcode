class Solution {
public:
    int diameterOfBinaryTree(const TreeNode *root) {
        ans = 0;
        getDepthOfBinaryTree(root);
        return ans;
    }

private:
    int ans;

    // 更新二叉树深度，同时更新直径
    int getDepthOfBinaryTree(const TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        auto leftDepth = getDepthOfBinaryTree(root->left);
        auto rightDepth = getDepthOfBinaryTree(root->right);
        ans = std::max(ans, leftDepth + rightDepth);
        return std::max(leftDepth, rightDepth) + 1;
    }

};