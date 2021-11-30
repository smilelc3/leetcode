//
// Created by l30014168 on 2021/11/29.
//

#include "TreeNode.h"

class Solution {
public:
    static TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, const TreeNode *target) {
        if (original == nullptr) {
            return nullptr;
        }
        if (original != target) {
            auto leftTarget = getTargetCopy(original->left, cloned->left, target);
            return leftTarget != nullptr ? leftTarget : getTargetCopy(original->right, cloned->right, target);
        } else {
            return cloned;
        }
    }
};