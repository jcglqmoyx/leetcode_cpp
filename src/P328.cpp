#include "ListNode.h"

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        ListNode *odd = new ListNode(0), *temp1 = odd, *even = new ListNode(0), *temp2 = even;
        bool flag = true;
        while (head) {
            ListNode *next = head->next;
            if (flag) {
                odd->next = head;
                odd = odd->next;
            } else {
                even->next = head;
                even = even->next;
            }
            head->next = nullptr;
            flag = !flag;
            head = next;
        }
        odd->next = temp2->next;
        return temp1->next;
    }
};