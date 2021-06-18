#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int low = 0, count = 0, prev = -2147483648;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != prev) {
                nums[low] = nums[i];
                low++;
                count++;
            }
            prev = nums[i];
        }
        return count;
    }
};