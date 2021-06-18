#include "ListNode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (headA != headB) {
            if (headA) headA = headA->next;
            else headA = a;
            if (headB) headB = headB->next;
            else headB = b;
        }
        return headA;
    }
};