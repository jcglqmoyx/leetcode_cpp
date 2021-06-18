//#include <vector>
//#include <cstdint>
//
//using namespace std;
//
//class Solution {
//public:
//    bool verifyPreorder(vector<int> &preorder) {
//        return verify(preorder, 0, (int) preorder.size() - 1, INT32_MIN);
//    }
//
//    bool verify(const vector<int> &preorder, int low, int high, int MIN) {
//        if (low >= high) return true;
//        int root = preorder[low];
//        int ptr = low + 1;
//        while (ptr <= high && preorder[ptr] < root) {
//            if (preorder[ptr] < MIN) return false;
//            ptr++;
//        }
//        return verify(preorder, low + 1, ptr - 1, MIN) && verify(preorder, ptr, high, preorder[low]);
//    }
//};

#include <vector>
#include <cstdint>
#include <stack>

using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int> &preorder) {
        int root = INT32_MIN;
        stack<int> stk;
        for (int num : preorder) {
            if (num < root) return false;
            while (!stk.empty() && stk.top() < num) {
                root = stk.top();
                stk.pop();
            }
            stk.push(num);
        }
        return true;
    }
};