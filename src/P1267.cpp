#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        int len = grid.size(), wid = grid[0].size();
        vector<int> row(len), col(wid);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j] && (row[i] > 1 || col[j] > 1)) {
                    count++;
                }
            }
        }
        return count;
    }
};