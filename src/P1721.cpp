//#include "ListNode.h"
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    ListNode *swapNodes(ListNode *head, int k) {
//        ListNode *dummy = head;
//        vector<ListNode *> nodes;
//        while (head) {
//            nodes.push_back(head);
//            head = head->next;
//        }
//        int temp = nodes[k - 1]->val;
//        nodes[k - 1]->val = nodes[nodes.size() - k]->val;
//        nodes[nodes.size() - k]->val = temp;
//        return dummy;
//    }
//};

#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *dummy = head;
        ListNode *first = head, *second = head;
        for (int i = 1; i < k; i++) {
            head = head->next;
        }
        first = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            fast = fast->next;
            second = second->next;
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        return dummy;
    }
};