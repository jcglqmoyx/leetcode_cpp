#include <vector>

using namespace std;

class Solution {
public:
    int calc(vector<int> &nums, int k) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > k) continue;
            int j = i + 1;
            while (j < n && nums[j] <= k) j++;
            int len = j - i;
            res += len * (len + 1) / 2;
            i = j;
        }
        return res;
    }

    int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
        return calc(nums, right) - calc(nums, left - 1);
    }
};