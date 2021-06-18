#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>> &mat) {
        bool visited[100] = {false};
        int len = (int) mat.size(), wid = (int) mat[0].size();
        int count = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (mat[i][j] == 1) {
                    if (!visited[j]) {
                        count += is_special(mat, i, j) ? 1 : 0;
                        visited[j] = true;
                    }
                }
            }
        }
        return count;
    }

    static bool is_special(const vector<vector<int>> &mat, int row, int col) {
        int count_one = 0;
        int len = (int) mat.size(), wid = (int) mat[0].size();
        for (int i = 0; i < len; i++) {
            if (mat[i][col]) {
                count_one++;
            }
            if (count_one > 1) {
                return false;
            }
        }
        for (int j = 0; j < wid; j++) {
            if (mat[row][j]) {
                count_one++;
            }
            if (count_one > 2) {
                return false;
            }
        }
        return true;
    }
};