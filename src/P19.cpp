#include "ListNode.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = head, *second = dummy;
        for (int i = 0; i < n; i++) first = first->next;
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};