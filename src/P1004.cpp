#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int res = 0;
        int left = 0;
        int count[2] = {0};
        for (int right = 0; right < A.size(); right++) {
            if (A[right] == 1) {
                count[1]++;
            } else {
                count[0]++;
                while (count[0] > K) {
                    count[A[left++]]--;
                }
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};