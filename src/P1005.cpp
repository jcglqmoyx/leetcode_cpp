#include <vector>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &A, int K) {
        for (int i = 0; i < K; i++) {
            sort(A.begin(), A.end());
            A[0] = -A[0];
        }
        int sum = 0;
        for (int num : A) {
            sum += num;
        }
        return sum;
    }
};