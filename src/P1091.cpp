#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    using PII = pair<int, int>;

    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) return -1;
        queue<PII> q;
        int step = 0;
        q.push({0, 0});
        while (!q.empty()) {
            step++;
            for (int cnt = q.size(); cnt; cnt--) {
                auto t = q.front();
                q.pop();
                int x = t.first, y = t.second;
                if (x == n - 1 && y == n - 1) return step;
                for (int a = x - 1; a <= x + 1; a++) {
                    for (int b = y - 1; b <= y + 1; b++) {
                        if (a == x && b == y) continue;
                        if (a < 0 || a >= n || b < 0 || b >= n) continue;
                        if (grid[a][b]) continue;
                        grid[a][b] = 1;
                        q.push({a, b});
                    }
                }
            }
        }
        return -1;
    }
};