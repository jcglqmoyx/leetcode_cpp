#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> dp;

    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int len = matrix.size(), wid = matrix[0].size();
        dp = vector<vector<int>>(len + 1, vector<int>(wid + 1, 0));
        for (int i = 1; i <= len; i++) {
            dp[i][1] = dp[i - 1][1] + matrix[i - 1][0];
        }
        for (int j = 1; j <= wid; j++) {
            dp[1][j] = dp[1][j - 1] + matrix[0][j - 1];
        }
        for (int i = 2; i <= len; i++) {
            for (int j = 2; j <= wid; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i - 1][j - 1] - dp[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }
};