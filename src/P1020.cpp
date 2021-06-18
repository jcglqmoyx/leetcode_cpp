#include <vector>

using namespace std;

class Solution {
public:
    int len, wid;

    int numEnclaves(vector<vector<int>> &A) {
        len = A.size();
        wid = A[0].size();
        for (int i = 0; i < len; i++) {
            if (A[i][0]) {
                flood_fill(A, i, 0);
            }
            if (A[i][wid - 1]) {
                flood_fill(A, i, wid - 1);
            }
        }
        for (int j = 0; j < wid; j++) {
            if (A[0][j]) {
                flood_fill(A, 0, j);
            }
            if (A[len - 1][j]) {
                flood_fill(A, len - 1, j);
            }
        }
        int count = 0;
        for (int i = 1; i < len; i++) {
            for (int j = 1; j < wid; j++) {
                if (A[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }

    void flood_fill(vector<vector<int>> &A, int i, int j) {
        if (i < 0 || j < 0 || i == len || j == wid || A[i][j] == 0) {
            return;
        }
        A[i][j] = 0;
        flood_fill(A, i + 1, j);
        flood_fill(A, i - 1, j);
        flood_fill(A, i, j + 1);
        flood_fill(A, i, j - 1);
    }
};