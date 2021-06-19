#include <queue>

using namespace std;

class Solution {
public:
    int leastMinutes(int n) {
        queue<pair<int, int>> q;
        q.push({0, 1});
        int step = -1;
        while (!q.empty()) {
            step++;
            for (int i = (int) q.size(); i; i--) {
                auto t = q.front();
                q.pop();
                if (t.first >= n) return step;
                q.push({t.first + t.second, t.second});
                if (t.second < n * 2) q.push({t.first, t.second * 2});
            }
        }
        return step;
    }
};