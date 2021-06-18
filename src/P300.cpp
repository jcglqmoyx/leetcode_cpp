#include <vector>

using namespace std;

//class Solution {
//public:
//    int lengthOfLIS(vector<int> &nums) {
//        int n = nums.size();
//        vector<int> dp(n, 1);
//        int max_len = 1;
//        for (int i = 1; i < n; i++) {
//            for (int j = i - 1; j >= 0; j--) {
//                if (nums[i] > nums[j]) {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//            }
//            max_len = max(max_len, dp[i]);
//        }
//        return max_len;
//    }
//};

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[1] = nums[0];
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > dp[len]) {
                dp[++len] = nums[i];
            } else {
                int l = 1, r = len;
                int position = 0;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (dp[mid] < nums[i]) {
                        l = mid + 1;
                        position = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                dp[position + 1] = nums[i];
            }
        }
        return len;
    }
};