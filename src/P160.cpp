#include "ListNode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *dummy1 = headA, *dummy2 = headB;
        int len1 = get_len(dummy1), len2 = get_len(dummy2);
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 0; i < len2 - len1; i++) {
                headB = headB->next;
            }
        }
        while (headA && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

    int get_len(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};