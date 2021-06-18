#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int res = 0;
        int p = 1;
        for (int i = 0, j = 0; j < n; j++) {
            p *= nums[j];
            while (i <= j && p >= k) {
                p /= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};