#include <vector>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        int res = 1;
        int n = intervals.size();
        int r = intervals.begin()->at(1);
        for (int i = 1; i < n; i++) {
            if (r <= intervals[i][0]) {
                res++;
                r = intervals[i][1];
            }
        }
        return n - res;
    }
};