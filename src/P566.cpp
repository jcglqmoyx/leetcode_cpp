#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int len = nums.size(), wid = nums[0].size();
        if (len * wid != r * c) {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                int index = i * wid + j;
                int row = index / c;
                int col = index % c;
                res[row][col] = nums[i][j];
            }
        }
        return res;
    }
};