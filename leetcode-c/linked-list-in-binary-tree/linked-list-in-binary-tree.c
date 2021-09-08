//
// Created by l30014168 on 2021/9/8.
//

#include <stdbool.h>
#include "ListNode.h"
#include "TreeNode.h"


// 判断以root起始，是否存在head的解，已经确保均不为NULL
bool isRootExistSameList(const struct ListNode* head, const struct TreeNode* root) {
    if (head == NULL) {
        return true;
    }
    if (root == NULL || root->val != head->val) {
        return false;
    }
    return isRootExistSameList(head->next, root->left) || isRootExistSameList(head->next, root->right);
}

bool isSubPath(const struct ListNode* head, const struct TreeNode* root){
    if (root == NULL) {
        return false;
    }
    return isRootExistSameList(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}
