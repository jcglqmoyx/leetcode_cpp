#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>> &A) {
        for (int i = 0; i < A.size(); i++) {
            if (A[i][0] != 1) {
                for (int j = 0; j < A[0].size(); j++) {
                    A[i][j] ^= 1;
                }
            }
        }
        int score = (int) A.size() * (int) pow(2, A[0].size() - 1);
        for (int j = 1; j < A[0].size(); j++) {
            int count_one = 0;
            for (int i = 0; i < A.size(); i++) {
                if (A[i][j] == 1) {
                    count_one++;
                }
            }
            score += max(count_one, (int) A.size() - count_one) * (int) pow(2, A[0].size() - j - 1);
        }
        return score;
    }
};