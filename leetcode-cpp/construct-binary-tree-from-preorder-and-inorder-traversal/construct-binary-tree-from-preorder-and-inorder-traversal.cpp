//
// Created by smile on 2021/4/12.
//

#include <vector>
#include <unordered_map>
#include "TreeNode.h"

class Solution {
public:
     TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {

        for (auto idx = 0; idx < inorder.size(); idx++) {
            indexMap[inorder[idx]] = idx;
        }

        return rebuildTreeByPreorderAndInorder(preorder, 0, preorder.size(),
                                               inorder, 0, inorder.size());
    }

private:
     std::unordered_map<int, int> indexMap;

     TreeNode *rebuildTreeByPreorderAndInorder(std::vector<int> &preorder, int preorderStart, int preorderEnd,
                                               std::vector<int> &inorder, int inorderStart, int inorderEnd) {
        if (preorderStart == preorderEnd or inorderStart == inorderEnd) {
            return nullptr;
        }
        auto root = new TreeNode(preorder[preorderStart]);

        // 在中序中找到根节点的位置，依次将先序序列和中序序列分成左右字树，分别构建左右子树
        int inorderRootIdx = indexMap[root->val];

        // 得到左子树的数目
        int leftSubtreeSize = inorderRootIdx - inorderStart;

        // 重构左子树
        root->left = rebuildTreeByPreorderAndInorder(preorder, preorderStart + 1, preorderStart + leftSubtreeSize + 1,
                                                     inorder, inorderStart, inorderRootIdx);

        // 重构右子树
        root->right = rebuildTreeByPreorderAndInorder(preorder, preorderStart + leftSubtreeSize + 1, preorderEnd,
                                                      inorder, inorderRootIdx + 1, inorderEnd);
        return root;
    }


};