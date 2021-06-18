#include "ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode *slow = head, *fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        while (head && fast && head != fast) {
            head = head->next;
            fast = fast->next;
        }
        return fast;
    }
};