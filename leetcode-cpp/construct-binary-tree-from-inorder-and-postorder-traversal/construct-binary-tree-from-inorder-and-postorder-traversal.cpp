//
// Created by smile on 2021/4/12.
//

#include <vector>
#include <unordered_map>
#include "TreeNode.h"

class Solution {
public:
    TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {

        for (auto idx = 0; idx < inorder.size(); idx++) {
            indexMap[inorder[idx]] = idx;
        }

        return rebuildTreeByInorderAndPostorder(inorder, 0, inorder.size(),
                                                postorder, 0, postorder.size());
    }

private:
    std::unordered_map<int, int> indexMap;

    TreeNode *rebuildTreeByInorderAndPostorder(std::vector<int> &inorder, int inorderStart, int inorderEnd,
                                               std::vector<int> &postorder, int postorderStart, int postorderEnd) {
        if (inorderStart == inorderEnd or postorderStart == postorderEnd) {
            return nullptr;
        }
        auto root = new TreeNode(postorder[postorderEnd - 1]);

        // 在中序中找到根节点的位置，依次将中序序列和后序序列分成左右字树，分别构建左右子树
        int inorderRootIdx = indexMap[root->val];

        // 得到右子树的数目
        int rightSubtreeSize = inorderEnd - inorderRootIdx - 1;

        // 重构右子树
        root->right = rebuildTreeByInorderAndPostorder(inorder, inorderRootIdx + 1, inorderEnd,
                                                       postorder, postorderEnd - rightSubtreeSize - 1,
                                                       postorderEnd - 1);

        // 重构左子树
        root->left = rebuildTreeByInorderAndPostorder(inorder, inorderStart, inorderRootIdx,
                                                      postorder, postorderStart, postorderEnd - rightSubtreeSize - 1);

        return root;
    }
};
