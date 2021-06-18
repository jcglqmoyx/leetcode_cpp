#include <vector>
#include "ListNode.h"
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> nums;
        ListNode *node = head;
        while (node) {
            nums.push_back(node->val);
            node = node->next;
        }
        stack<int> s;
        int n = nums.size();
        vector<int> res(n);
        for (int i = n - 1; ~i; i--) {
            while (!s.empty() && nums[s.top()] <= nums[i]) s.pop();
            if (!s.empty()) res[i] = nums[s.top()];
            else res[i] = 0;
            s.push(i);
        }
        return res;
    }
};