//
// Created by smile on 2022/12/11.
//

#include <vector>

class Solution {
public:
    std::vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int listLength = 0;
        auto pNode = head;
        while (pNode != nullptr) {
            listLength++;
            pNode = pNode->next;
        }

        std::vector<ListNode *> ans(k, nullptr);
        auto divRet = std::div(listLength, k);
        pNode = head;
        for (int idx = 0; idx < std::min(listLength, k); ++idx) {
            auto partLength = divRet.quot;
            if (divRet.rem != 0) {
                partLength++;
                divRet.rem--;
            }

            auto partNode = new ListNode(pNode->val);
            ans[idx] = partNode;
            pNode = pNode->next;
            partLength--;
            while (partLength > 0) {
                partNode->next = new ListNode(pNode->val);
                partNode = partNode->next;
                pNode = pNode->next;
                partLength--;
            }
        }
        return ans;
    }
};
