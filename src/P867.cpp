#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        vector<vector<int>> res(A[0].size(), vector<int>(A.size(), 0));
        for (int i = 0; i < A[0].size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                res[i][j] = A[j][i];
            }
        }
        return res;
    }
};