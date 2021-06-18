#include "ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode(0);
        ListNode *dummy_head = ans;
        int carry = 0;
        while (l1 || l2) {
            if (l1 && l2) {
                int x = l1->val, y = l2->val;
                int sum = x + y + carry;
                carry = sum / 10;
                dummy_head->next = new ListNode(sum % 10);
                dummy_head = dummy_head->next;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                int x = l1->val;
                int sum = x + carry;
                carry = sum / 10;
                dummy_head->next = new ListNode(sum % 10);
                dummy_head = dummy_head->next;
                l1 = l1->next;
            } else if (l2) {
                int y = l2->val;
                int sum = y + carry;
                carry = sum / 10;
                dummy_head->next = new ListNode(sum % 10);
                dummy_head = dummy_head->next;
                l2 = l2->next;
            }
        }
        if (carry) {
            dummy_head->next = new ListNode(1);
        }
        return ans->next;
    }
};