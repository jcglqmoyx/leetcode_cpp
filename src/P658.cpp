#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = arr.size();
        int p = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        vector<int> res;
        res.reserve(k);
        if (p == 0) {
            for (int i = 0; i < k; i++) {
                res.push_back(arr[i]);
            }
            return res;
        } else if (p == n) {
            for (int i = n - k; i < n; i++) {
                res.push_back(arr[i]);
            }
            return res;
        }
        int l = p - 1, r = p;
        while (r - l - 1 < k) {
            if (l >= 0 && r < n) {
                if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                    l--;
                } else {
                    r++;
                }
            } else if (l >= 0) {
                l--;
            } else {
                r++;
            }
        }
        for (int i = l + 1; i < r; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};