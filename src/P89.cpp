#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> nums = {0, 1};
        nums.reserve(2 << n);
        for (int i = 2; i <= n; i++) {
            for (int index = (int) nums.size() - 1; index >= 0; index--) {
                nums.push_back((nums[index] + (1 << (i - 1))));
            }
        }
        return nums;
    }
};