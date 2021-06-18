//#include "ListNode.h"
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    vector<int> nums;
//
//    Solution(ListNode *head) {
//        while (head) {
//            nums.push_back(head->val);
//            head = head->next;
//        }
//    }
//
//    int getRandom() {
//        int n = nums.size();
//        int index = rand() % n;
//        return nums[index];
//    }
//};



#include <cstdlib>
#include "ListNode.h"

class Solution {
public:
    ListNode *p;

    Solution(ListNode *head) {
        p = head;
    }

    int getRandom() {
        ListNode *temp = p;
        int count = 1;
        int ans = 0;
        while (temp) {
            if (rand() % count == 0) {
                ans = temp->val;
            }
            count++;
            temp = temp->next;
        }
        return ans;
    }
};