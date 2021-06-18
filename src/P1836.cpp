#include <unordered_map>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *deleteDuplicatesUnsorted(ListNode *head) {
        unordered_map<int, int> hash;
        ListNode *cur = head;
        while (cur) {
            hash[cur->val]++;
            cur = cur->next;
        }
        auto *dummy = new ListNode();
        cur = dummy;
        while (head) {
            ListNode *next = head->next;
            if (hash[head->val] == 1) {
                cur->next = head;
                cur = head;
                cur->next = nullptr;
            }
            head = next;
        }
        return dummy->next;
    }
};