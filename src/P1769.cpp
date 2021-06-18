#include <vector>
#include <string>

using namespace std;

//class Solution {
//public:
//    vector<int> minOperations(string boxes) {
//        int n = boxes.size();
//        vector<int> res(n);
//        for (int i = 0; i < n; i++) {
//            int temp = 0;
//            for (int j = 0; j < n; j++) {
//                if (j == i) continue;
//                if (boxes[j] == '1') {
//                    temp += abs(j - i);
//                }
//            }
//            res[i] = temp;
//        }
//        return res;
//    }
//};


class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> dp(n);
        int left = 0, right = 0;
        for (int i = 1; i < n; i++) {
            if (boxes[i] == '1') {
                dp[0] += i;
                right++;
            }
        }
        if (boxes[0] == '1') left++;
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + left - right;
            if (boxes[i] == '1') {
                left++;
                right--;
            }
        }
        return dp;
    }
};