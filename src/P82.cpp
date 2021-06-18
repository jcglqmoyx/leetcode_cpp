#include "ListNode.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        auto *dummy = new ListNode(0, head), *cur = dummy;
        while (head) {
            if (head->next && head->val == head->next->val) {
                cur->next = nullptr;
                while (head && head->next && head->val == head->next->val) {
                    head = head->next;
                }
                if (head) {
                    head = head->next;
                }
            } else {
                cur->next = head;
                cur = cur->next;
                head = head->next;
            }
        }
        return dummy->next;
    }
};