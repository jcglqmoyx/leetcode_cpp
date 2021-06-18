#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    int countPairs(vector<int> &deliciousness) {
        ll res = 0;
        unordered_map<int, int> cnt;
        unordered_set<int> power;
        for (int d : deliciousness) cnt[d]++;
        for (int i = 0; i <= 21; i++) power.insert(1 << i);
        for (auto[d, v] : cnt) {
            for (int p : power) {
                if (cnt.count(p - d) && d < p - d) {
                    res += cnt[d] * cnt[p - d];
                }
            }
            if (power.count(d)) {
                res += (ll) cnt[d] * (cnt[d] - 1) / 2;
            }
        }
        return (int) (res % MOD);
    }
};