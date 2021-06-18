#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int n = A.size();
        if (n < 3) return 0;
        int len;
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (A[i - 2] - A[i - 1] == A[i - 1] - A[i]) {
                int diff = A[i - 1] - A[i];
                int j = i + 1;
                while (j < n && A[j - 1] - A[j] == diff) {
                    j++;
                }
                len = j - i + 2;
                res += (len - 1) * (len - 2) / 2;
                i = j;
            }
        }
        return res;
    }
};