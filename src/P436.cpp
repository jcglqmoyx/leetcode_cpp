#include <vector>
#include <map>

using namespace std;
typedef vector<int> VI;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        map<int, int> m;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            m[intervals[i][0]] = i;
        }

        VI res;
        res.reserve(n);
        for (auto &interval : intervals) {
            auto p = m.lower_bound(interval[1]);
            if (p == m.end()) res.push_back(-1);
            else res.push_back(p->second);
        }
        return res;
    }
};