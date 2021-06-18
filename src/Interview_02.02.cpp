#include "ListNode.h"

class Solution {
public:
    int kthToLast(ListNode *head, int k) {
        ListNode *fast = head;
        for (int i = 0; i < k; i++) fast = fast->next;
        while (fast) {
            fast = fast->next;
            head = head->next;
        }
        return head->val;
    }
};