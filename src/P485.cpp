#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int len = 0, max_len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                len++;
                max_len = max(max_len, len);
            } else {
                len = 0;
            }
        }
        return max_len;
    }
};