#include <vector>

using namespace std;

class Solution {
public:
    int len, wid;
    int max_gold;

    int getMaximumGold(vector<vector<int>> &grid) {
        len = grid.size();
        wid = grid[0].size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j] != 0) {
                    dfs(grid, i, j, 0);
                }
            }
        }
        return max_gold;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int gold) {
        if (i < 0 || j < 0 || i == len || j == wid || grid[i][j] == 0) return;
        gold += grid[i][j];
        max_gold = max(max_gold, gold);
        int value = grid[i][j];
        grid[i][j] = 0;
        dfs(grid, i + 1, j, gold);
        dfs(grid, i - 1, j, gold);
        dfs(grid, i, j + 1, gold);
        dfs(grid, i, j - 1, gold);
        grid[i][j] = value;
    }
};