#include "ListNode.h"

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (head->val == val) return head->next;
        ListNode *dummy = head;
        while (head && head->next) {
            if (head->next->val == val) {
                if (head->next->next) head->next = head->next->next;
                else head->next = nullptr;

            }
            head = head->next;
        }
        return dummy;
    }
};