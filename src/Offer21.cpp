#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        int i = 0, j = 0;
        for (; j < nums.size(); j++) {
            while (j < nums.size() && nums[j] % 2 == 1) {
                swap(nums[i++], nums[j]);
                if (i >= j) j++;
            }
        }
        return nums;
    }
};