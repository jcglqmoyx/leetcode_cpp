#include "ListNode.h"

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        auto *dummy = new ListNode(0, head);
        head = dummy;
        for (int i = 1; i < m; i++) head = head->next;
        ListNode *l = head->next;
        ListNode *temp = head;
        for (int i = 0; i < n - m; i++) head = head->next;
        ListNode *r = head->next;
        ListNode *r_next = r->next;
        r->next = nullptr;
        l = reverse(l);
        temp->next = l;
        while (l && l->next) l = l->next;
        l->next = r_next;
        return dummy->next;
    }

    ListNode *reverse(ListNode *node) {
        ListNode *prev = nullptr;
        while (node) {
            auto *next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};