#include <vector>
#include <unordered_map>

using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 133331;

ULL h[N], p[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

class Solution {
public:
    vector<vector<int>> _paths;
    unordered_map<ULL, int> cnt, s;

    bool check(int mid) {
        cnt.clear(), s.clear();
        p[0] = 1;
        int k = 0;
        for (auto &str : _paths) {
            int n = (int) str.size();
            for (int i = 1; i <= n; i++) {
                p[i] = p[i - 1] * P;
                h[i] = h[i - 1] * P + str[i - 1];
            }
            for (int i = mid; i <= n; i++) {
                ULL t = get(i - mid + 1, i);
                if (!s.count(t) || s[t] != k) {
                    s[t] = k;
                    cnt[t]++;
                }
            }
            k++;
        }
        int res = 0;
        for (auto &[k, v] : cnt) res = max(res, v);
        return res == _paths.size();
    }

    int longestCommonSubpath(int n, vector<vector<int>> &paths) {
        _paths = paths;
        int l = 0, r = N;
        for (auto &path : paths) {
            r = min(r, (int) path.size());
        }
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};