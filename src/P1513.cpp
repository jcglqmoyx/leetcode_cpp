#include <string>

using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    int numSub(string s) {
        ll res = 0;
        int n = s.length();
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                len++;
                if (i == n - 1) {
                    res += (ll) len * (len + 1) / 2;
                }
            } else {
                res += (ll) len * (len + 1) / 2;
                len = 0;
            }
        }
        return (int) (res % MOD);
    }
};