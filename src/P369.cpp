#include <stack>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *plusOne(ListNode *head) {
        ListNode *dummy = head;
        stack<ListNode *> stk;
        while (dummy) {
            stk.push(dummy);
            dummy = dummy->next;
        }
        int carry = 1;
        while (!stk.empty()) {
            ListNode *node = stk.top();
            int sum = node->val + carry;
            node->val = sum % 10;
            carry = sum / 10;
            stk.pop();
        }
        if (carry) {
            auto *new_head = new ListNode(1);
            new_head->next = head;
            return new_head;
        }
        return head;
    }
};