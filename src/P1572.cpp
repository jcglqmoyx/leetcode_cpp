#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>> &mat) {
        int len = mat.size();
        int center = mat[len / 2][len / 2];
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += mat[i][i] + mat[i][len - 1 - i];
        }
        if ((len & 1) == 1) {
            sum -= center;
        }
        return sum;
    }
};