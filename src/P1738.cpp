#include <vector>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        int len = matrix.size(), wid = matrix[0].size();
        for (int j = 1; j < wid; j++) matrix[0][j] ^= matrix[0][j - 1];
        for (int i = 1; i < len; i++) matrix[i][0] ^= matrix[i - 1][0];
        for (int i = 1; i < len; i++)
            for (int j = 1; j < wid; j++)
                matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
        vector<int> result(len * wid);
        int index = 0;
        for (int i = 0; i < len; i++) for (int j = 0; j < wid; j++) result[index++] = matrix[i][j];
        sort(result.begin(), result.end());
        return result[result.size() - k];
    }
};