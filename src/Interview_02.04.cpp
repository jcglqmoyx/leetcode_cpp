#include "ListNode.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        auto *smaller = new ListNode(0, head), *greater = new ListNode(0);
        auto *smaller_head = smaller, *greater_head = greater;
        while (head) {
            if (head->val < x) {
                smaller_head->next = new ListNode(head->val);
                smaller_head = smaller_head->next;
            } else {
                greater_head->next = new ListNode(head->val);
                greater_head = greater_head->next;
            }
            head = head->next;
        }
        smaller_head->next = greater->next;
        return smaller->next;
    }
};