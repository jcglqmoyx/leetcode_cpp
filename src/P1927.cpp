#include <string>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = (int) num.size();
        int l = 0, r = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] != '?') l += num[i] - '0';
            else cnt1++;
            if (num[i + n / 2] != '?') r += num[i + n / 2] - '0';
            else cnt2++;
        }
        if (cnt1 == 0 && cnt2 == 0) return l != r;
        if (l == r) return cnt1 != cnt2;
        if (l < r && cnt1 <= cnt2) return true;
        if (l > r && cnt1 >= cnt2) return true;
        if (l + (cnt1 + 1) / 2 * 9 > r + (cnt2 + 1) / 2 * 9) return true;
        if (l + (cnt1 + 1) / 2 * 9 < r + (cnt2 + 1) / 2 * 9) return true;
        if (abs(l - r) <= 9 && abs(cnt1 - cnt2) <= 1) return true;
        return false;
    }
};