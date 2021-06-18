#include "ListNode.h"

class Solution {
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *dummy = list1;
        for (int i = 1; i < a; i++) list1 = list1->next;
        ListNode *start = list1;
        for (int i = 0; i <= b - a; i++) start = start->next;
        list1->next = list2;
        while (list2 && list2->next) list2 = list2->next;
        list2->next = start->next;
        return dummy;
    }
};