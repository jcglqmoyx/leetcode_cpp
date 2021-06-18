#include "ListNode.h"

//class Solution {
//public:
//    ListNode *insertionSortList(ListNode *head) {
//        ListNode *dummy = head;
//        while (head) {
//            ListNode *node = dummy;
//            while (node != head) {
//                if (head->val < node->val) {
//                    int temp = head->val;
//                    head->val = node->val;
//                    node->val = temp;
//                }
//                node = node->next;
//            }
//            head = head->next;
//        }
//        return dummy;
//    }
//};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        auto *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *lastSorted = head;
        ListNode *curr = head->next;
        while (curr != nullptr) {
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode *prev = dummyHead;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        return dummyHead->next;
    }
};