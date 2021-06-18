#include "ListNode.h"

//class Solution {
//public:
//    int get_len(ListNode *head) {
//        int len = 0;
//        ListNode *dummy = head;
//        while (dummy) {
//            len++;
//            dummy = dummy->next;
//        }
//        return len;
//    }
//
//    ListNode *rotateRight(ListNode *head, int k) {
//        if (!head) return nullptr;
//        int len = get_len(head);
//        k = k % len;
//        if (k == 0) return head;
//        auto *dummy = new ListNode(0, head);
//        for (int i = 0; i < len - k - 1; i++) {
//            head = head->next;
//        }
//        ListNode *new_head = head->next;
//        ListNode *ans = new_head;
//        while (new_head && new_head->next) {
//            new_head = new_head->next;
//        }
//        head->next = nullptr;
//        new_head->next = dummy->next;
//        return ans;
//    }
//};


class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next) return head;
        ListNode *dummy = head;
        int len = 1;
        while (dummy->next) {
            len++;
            dummy = dummy->next;
        }
        dummy->next = head;
        for (int i = 0; i < len - k % len - 1; i++) {
            head = head->next;
        }
        ListNode *ans = head->next;
        head->next = nullptr;
        return ans;
    }
};