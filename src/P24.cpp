#include "ListNode.h"

//class Solution {
//public:
//    ListNode *swapPairs(ListNode *head) {
//        if (!head || !head->next) return head;
//        ListNode *next = head->next;
//        head->next = swapPairs(next->next);
//        next->next = head;
//        return next;
//    }
//};


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        auto *dummy = new ListNode(0, head);
        ListNode *temp = dummy;
        while (temp->next && temp->next->next) {
            ListNode *node1 = temp->next, *node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummy->next;
    }
};