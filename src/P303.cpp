#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> nums;

    NumArray(vector<int> &nums) {
        this->nums = nums;
        for (int i = 1; i < nums.size(); i++) {
            this->nums[i] += this->nums[i - 1];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return this->nums[j];
        } else {
            return this->nums[j] - this->nums[i - 1];
        }
    }
};