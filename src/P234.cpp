#include "ListNode.h"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *temp = new ListNode(0), *dummy = head, *cp = temp;
        while (dummy) {
            temp->next = new ListNode(dummy->val);
            temp = temp->next;
            dummy = dummy->next;
        }
        ListNode *reversed_list = reverse(head);
        while (reversed_list) {
            if (cp->next->val != reversed_list->val) {
                return false;
            }
            cp = cp->next;
            reversed_list = reversed_list->next;
        }
        return true;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};