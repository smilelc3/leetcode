//
// Created by smile on 2021/3/16.
//
#include <ListNode.h>

class Solution {
public:
    static bool hasCycle(ListNode *head) {

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return false;
        }
        ListNode *Fast, *Slow;
        Slow = head->next;
        Fast = head->next->next;

        while (Fast != Slow && Fast->next != nullptr && Slow->next != nullptr) {
            Slow = Slow->next;
            Fast = Fast->next;
            if (Fast->next != nullptr) {
                Fast = Fast->next;
            } else {
                return false;
            }
        }
        return Fast == Slow;

    }

};