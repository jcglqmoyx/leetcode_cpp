#include "ListNode.h"

class Solution {
public:
    ListNode *deleteNodes(ListNode *head, int m, int n) {
        ListNode *res = head;
        while (head) {
            for (int i = 0; i < m - 1 && head; i++) {
                head = head->next;
            }
            if (!head) break;
            ListNode *temp = head->next;
            for (int j = 0; j < n && temp; j++) {
                temp = temp->next;
            }
            head->next = temp;
            head = temp;
        }
        return res;
    }
};