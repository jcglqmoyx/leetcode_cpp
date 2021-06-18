#include "ListNode.h"

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        auto *dummy = new ListNode(0, head), *node = dummy;
        while (node && node->next) {
            while (node->next && node->next->val == val) {
                node->next = node->next->next;
            }
            node = node->next;
        }
        return dummy->next;
    }
};