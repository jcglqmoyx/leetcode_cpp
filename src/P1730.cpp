#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int getFood(vector<vector<char>> &grid) {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    q.push({i, j});
                    visited[i][j] = true;
                    break;
                }
            }
        }
        int len = 0;
        while (!q.empty()) {
            len++;
            int size = q.size();
            while (size--) {
                auto[x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                        if (grid[nx][ny] == '#') {
                            return len;
                        } else if (grid[nx][ny] == 'O') {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return -1;
    }
};