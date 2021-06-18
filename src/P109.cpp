#include "TreeNode.h"
#include "ListNode.h"

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return construct(head, nullptr);
    }

    ListNode *get_mid(ListNode *start, ListNode *end) {
        ListNode *fast = start, *slow = start;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode *construct(ListNode *start, ListNode *end) {
        if (start == end) return nullptr;
        ListNode *mid = get_mid(start, end);
        auto *root = new TreeNode(mid->val);
        root->left = construct(start, mid);
        root->right = construct(mid->next, end);
        return root;
    }
};