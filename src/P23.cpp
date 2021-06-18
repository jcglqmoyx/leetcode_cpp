#include <vector>
#include <queue>
#include "ListNode.h"

using namespace std;

//class Solution {
//public:
//    ListNode *mergeKLists(vector<ListNode *> &lists) {
//        if (lists.empty()) return nullptr;
//        ListNode *dummy_head = new ListNode(), *head = dummy_head;
//        while (true) {
//            int min_value = 10000;
//            int count_null_list = 0;
//            ListNode *p = nullptr;
//            for (int i = 0; i < lists.size(); i++) {
//                if (!lists[i]) {
//                    count_null_list++;
//                    continue;
//                }
//                if (lists[i]->val <= min_value) {
//                    p = lists[i];
//                    min_value = lists[i]->val;
//                }
//            }
//            if (count_null_list == lists.size()) break;
//            head->next = p;
//            head = head->next;
//            for (int i = 0; i < lists.size(); i++) {
//                if (lists[i] == p) {
//                    lists[i] = lists[i]->next;
//                    break;
//                }
//            }
//        }
//        return dummy_head->next;
//    }
//};

class Solution {
public:
    struct Status {
        int val;
        ListNode *node;

        bool operator<(const Status &status) const {
            return this->val > status.val;
        }
    };

    static bool cmp(ListNode *a, ListNode *b) {
        return a->val < b->val;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<Status> q;
        for (ListNode *list : lists) {
            if (list) {
                q.push({list->val, list});
            }
        }
        auto *dummy_head = new ListNode(0), *head = dummy_head;
        while (!q.empty()) {
            head->next = q.top().node;
            q.pop();
            head = head->next;
            if (head->next) {
                q.push({head->next->val, head->next});
            }
        }
        return dummy_head->next;
    }
};