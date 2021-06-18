#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int len, wid;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int orangesRotting(vector<vector<int>> &grid) {
        len = grid.size();
        wid = grid[0].size();
        visited.resize(len, vector<bool>(wid, false));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j] == 2) {
                    dfs(grid, i, j);
                }
            }
        }
        int minutes = -1;
        while (!q.empty()) {
            minutes++;
            int size = q.size();
            while (size--) {
                auto[x, y]= q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < len && ny >= 0 && ny < wid && grid[nx][ny] == 1 && !visited[nx][ny]) {
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return minutes == -1 ? 0 : minutes;
    }

    void dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i == len || j == wid || grid[i][j] != 2 || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        q.push({i, j});
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};