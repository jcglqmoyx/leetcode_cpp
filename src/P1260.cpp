#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        queue<int> q;
        for (int i = grid.size() - 1; i >= 0; i--)
            for (int j = grid[0].size() - 1; j >= 0; j--)
                q.push(grid[i][j]);
        for (; k > 0; k--) {
            int n = q.front();
            q.pop();
            q.push(n);
        }
        for (int i = grid.size() - 1; i >= 0; i--)
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                grid[i][j] = q.front();
                q.pop();
            }
        return grid;
    }
};