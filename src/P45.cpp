#include <vector>

using namespace std;

//class Solution {
//public:
//    int jump(vector<int> &nums) {
//        int n = nums.size();
//        vector<int> dp(n, 1000);
//        dp[0] = 0;
//        for (int i = 1; i < n; i++) {
//            for (int j = i - 1; j >= 0; j--) {
//                if (nums[j] >= i - j) {
//                    dp[i] = min(dp[i], dp[j] + 1);
//                }
//            }
//        }
//        return dp[n - 1];
//    }
//};

class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        int steps = 0;
        int end = 0;
        int max_position = 0;
        for (int i = 0; i < n - 1; i++) {
            max_position = max(nums[i] + i, max_position);
            if (i == end) {
                end = max_position;
                steps++;
            }
        }
        return steps;
    }
};