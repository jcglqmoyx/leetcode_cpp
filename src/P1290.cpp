#include "ListNode.h"

class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int decimal = 0;
        while (head) {
            decimal = decimal * 2 + head->val;
            head = head->next;
        }
        return decimal;
    }
};