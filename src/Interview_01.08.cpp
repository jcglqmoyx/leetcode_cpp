#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        bool col = false, row = false;
        int len = matrix.size(), wid = matrix[0].size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        row = true;
                    }
                    if (j == 0) {
                        col = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < len; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < wid; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < wid; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < len; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (col) {
            for (int i = 0; i < len; i++) {
                matrix[i][0] = 0;
            }
        }
        if (row) {
            for (int j = 0; j < wid; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};