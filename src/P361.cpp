#include <vector>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int len = grid.size(), wid = grid[0].size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j] == '0') {
                    int enemy = 0;
                    for (int index = 0; index < 4; index++) {
                        int x = i;
                        int y = j;
                        while (true) {
                            x += dx[index];
                            y += dy[index];
                            if (x < 0 || y < 0 || x == len || y == wid || grid[x][y] == 'W') break;
                            if (grid[x][y] == 'E') {
                                enemy++;
                            }
                        }
                    }
                    res = max(res, enemy);
                }
            }
        }
        return res;
    }
};