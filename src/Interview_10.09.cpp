#include <vector>

using namespace std;

#include <vector>

using namespace std;

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        int len = matrix.size(), wid = matrix[0].size();
        int i = len - 1, j = 0;
        while (i >= 0 && j < wid) {
            while (i >= 0 && matrix[i][j] > target) {
                i--;
            }
            if (i < 0) break;
            if (matrix[i][j] == target) return true;
            while (j < wid && matrix[i][j] < target) j++;
            if (j == wid) break;
        }
        return false;
    }
};