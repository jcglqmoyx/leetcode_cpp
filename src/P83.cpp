#include "ListNode.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        auto *dummy = new ListNode(0);
        dummy->next = head;
        while (head && head->next) {
            while (head->next && head->val == head->next->val) {
                head->next = head->next->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};