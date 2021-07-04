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
        for (int i = 0; i < _paths.size(); i++) {
            int n = (int) _paths[i].size();
            for (int j = 1; j <= n; j++) {
                h[j] = h[j - 1] * P + _paths[i][j - 1];
            }
            for (int j = mid; j <= n; j++) {
                ULL t = get(j - mid + 1, j);
                if (!s.count(t) || s[t] != i) {
                    s[t] = i;
                    cnt[t]++;
                }
            }
        }
        int res = 0;
        for (auto &[k, v] : cnt) res = max(res, v);
        return res == _paths.size();
    }

    int longestCommonSubpath(int n, vector<vector<int>> &paths) {
        _paths = paths;
        int l = 0, r = N;
        for (auto &path : paths) r = min(r, (int) path.size());
        p[0] = 1;
        for (int i = 1; i < N; i++) p[i] = p[i - 1] * P;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};