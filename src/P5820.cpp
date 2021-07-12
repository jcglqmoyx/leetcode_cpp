#include <vector>

using namespace std;

class Solution {
public:
    int get_time(vector<int> &p, vector<int> &q) {
        return (abs(p[0] - q[0]) + abs(p[1] - q[1]) + 1) / 2;
    }

    int minDayskVariants(vector<vector<int>> &points, int k) {
        int n = (int) points.size();
        vector<vector<int>> time(n, vector<int>(n));
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                time[i][j] = get_time(points[i], points[j]);
            }
        }
        int res = 1e9;
        for (int status = 0; status < 1 << n; status++) {
            if (__builtin_popcount(status) != k) continue;
            int cur = 0;
            for (int i = 0; i < n; i++) {
                if (status >> i & 1) {
                    for (int j = i + 1; j < n; j++) {
                        if (status >> j & 1) {
                            cur = max(cur, time[i][j]);
                        }
                    }
                }
            }
            res = min(res, cur);
        }
        return res;
    }
};