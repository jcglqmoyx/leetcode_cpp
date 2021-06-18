#include <vector>

using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>> &grid) {
        int len = grid.size(), wid = grid[0].size();
        if (len < 2 || wid < 2) return 0;
        int count = 0;
        vector<vector<int>> dp(len, vector<int>(wid, 0));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j]) {
                    for (int k = j + 1; k < wid; k++) {
                        if (grid[i][k]) {
                            count += dp[j][k];
                            dp[j][k]++;
                        }
                    }
                }
            }
        }
        return count;
    }
};