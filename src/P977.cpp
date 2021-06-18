#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {
        vector<int> res(A.size());
        int i = 0, j = (int) A.size() - 1;
        int index = j;
        while (i <= j) {
            int x = A[i] * A[i];
            int y = A[j] * A[j];
            if (x > y) {
                res[index--] = x;
                i++;
            } else {
                res[index--] = y;
                j--;
            }
        }
        return res;
    }
};