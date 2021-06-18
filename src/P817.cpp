#include <vector>
#include <unordered_set>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    int numComponents(ListNode *head, vector<int> &G) {
        unordered_set<int> set(G.begin(), G.end());
        int prev = -2;
        int count = 0;
        while (head) {
            if (set.count(prev) && set.count(head->val)) {
                count++;
            }
            prev = head->val;
            head = head->next;
        }
        return (int) G.size() - count;
    }
};