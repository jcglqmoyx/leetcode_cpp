#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K) {
        int len = (int) mat.size(), wid = (int) mat[0].size();
        vector<vector<int>> res(len, vector<int>(wid, 0));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                int sum = 0;
                for (int m = i - K; m <= i + K; m++) {
                    for (int n = j - K; n <= j + K; n++) {
                        if (m >= 0 && m < len && n >= 0 && n < wid) {
                            sum += mat[m][n];
                        }
                    }
                }
                res[i][j] = sum;
            }
        }
        return res;
    }
};