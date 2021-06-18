#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        int len = grid.size(), wid = grid[0].size();
        for (int j = 1; j < wid; j++) grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < len; i++) grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < len; i++) {
            for (int j = 1; j < wid; j++) {
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[len - 1][wid - 1];
    }
};