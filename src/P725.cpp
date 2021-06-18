#include <vector>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        int total_len = 0;
        ListNode *dummy = root;
        while (dummy) {
            total_len++;
            dummy = dummy->next;
        }
        int sub_size = total_len / k;
        int temp = total_len - sub_size * k;
        vector<ListNode *> parts(k);
        for (int index = 0; index < k; index++) {
            auto *head = new ListNode(0, root);
            int len = index < temp ? sub_size + 1 : sub_size;
            for (int i = 0; i < len - 1; i++) {
                if (root) {
                    root = root->next;
                }
            }
            if (root) {
                ListNode *next = root->next;
                root->next = nullptr;
                root = next;
            }
            parts[index] = head->next;
            delete head;
        }
        return parts;
    }
};