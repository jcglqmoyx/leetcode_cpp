#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> s1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> s2(m + 1, vector<int>(n + 2, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        set<int> s;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s.insert(grid[i - 1][j - 1]);
                for (int k = 1; i - k >= 1 && i + k <= m && j - k >= 1 && j + k <= n; k++) {
                    int a = s2[i][j - k] - s2[i - k][j];
                    int b = s1[i][j + k] - s1[i - k][j];
                    int c = s2[i + k][j] - s2[i][j + k];
                    int d = s1[i + k][j] - s1[i][j - k];
                    s.insert(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
                }
            }
        }
        while (s.size() > 3) s.erase(s.begin());
        return vector<int>(s.rbegin(), s.rend());
    }
};