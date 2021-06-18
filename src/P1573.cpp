#include <string>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    using LL = long long;

    int numWays(string s) {
        int cnt = 0, n = s.length(), low = 0, high = n - 1;
        for (char c : s) if (c == '1') cnt++;
        if (cnt % 3) return 0;
        if (cnt == 0) return (int) ((LL) (n - 1) * (n - 2) / 2 % MOD);
        int left = 0, right = 0;
        while (left < cnt / 3) {
            if (s[low] == '1') left++;
            low++;
        }
        while (right < cnt / 3) {
            if (s[high] == '1') right++;
            high--;
        }
        int l = low, r = high;
        while (s[l] == '0') l++;
        while (s[r] == '0') r--;
        return (int) ((LL) (l - low + 1) * (high - r + 1) % MOD);
    }
};