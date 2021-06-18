#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        int distance = 0;
        for (int i = 0; i < 32; i++) {
            int count_one = 0;
            for (int index = 0; index < nums.size(); index++) {
                if (nums[index] & 1) count_one++;
                nums[index] >>= 1;
            }
            distance += (nums.size() - count_one) * count_one;
        }
        return distance;
    }
};