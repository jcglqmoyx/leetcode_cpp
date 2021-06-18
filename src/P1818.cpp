#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
        ll sum = 0;
        int n = nums1.size();
        set<ll> s;
        for (int i = 0; i < n; i++) {
            sum += abs(nums1[i] - nums2[i]);
            s.insert(nums1[i]);
        }
        ll res = sum;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            auto p = s.lower_bound(nums2[i]);
            if (p != s.end()) {
                res = min(res, sum - diff + abs(*(p) - nums2[i]));
            }
            if (p != s.begin()) {
                res = min(res, sum - diff + abs(*(--p) - nums2[i]));
            }
        }
        return (int) (res % MOD);
    }
};