#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n;

    int shortestBridge(vector<vector<int>> &A) {
        queue<pair<int, int>> q;
        n = A.size();
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j]) {
                    dfs(A, q, visited, i, j);
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        int len = -1;
        while (!q.empty()) {
            len++;
            int size = q.size();
            while (size--) {
                auto[x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                        if (A[nx][ny]) return len;
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return len;
    }

    void dfs(vector<vector<int>> &A, queue<pair<int, int>> &q, vector<vector<bool>> &visited, int i, int j) {
        if (i < 0 || j < 0 || i == n || j == n || visited[i][j] || A[i][j] == 0) return;
        visited[i][j] = true;
        q.push({i, j});
        dfs(A, q, visited, i + 1, j);
        dfs(A, q, visited, i - 1, j);
        dfs(A, q, visited, i, j + 1);
        dfs(A, q, visited, i, j - 1);
    }
};