#include <vector>

using namespace std;

//class Solution {
//public:
//    int numTrees(int n) {
//        vector<int> dp(n + 1);
//        dp[0] = 1, dp[1] = 1;
//        for (int i = 2; i <= n; i++) {
//            for (int j = 1; j <= i; j++) {
//                dp[i] += dp[j - 1] * dp[i - j];
//            }
//        }
//        return dp[n];
//    }
//};

class Solution {
public:
    int numTrees(int n) {
        long ans = 1;
        for (int i = 1; i < n; i++) {
            ans = 2 * (2 * i + 1) * ans / (i + 2);
        }
        return (int) ans;
    }
};