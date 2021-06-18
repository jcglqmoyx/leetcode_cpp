#include "ListNode.h"
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode *removeDuplicateNodes(ListNode *head) {
        unordered_set<int> set;
        vector<int> arr;
        while (head) {
            if (!set.count(head->val)) {
                arr.push_back(head->val);
                set.insert(head->val);
            }
            head = head->next;
        }
        ListNode *node = new ListNode(0), *dummy = node;
        for (int val : arr) {
            node->next = new ListNode(val);
            node = node->next;
        }
        return dummy->next;
    }
};