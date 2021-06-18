#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) return false;
        stack<int> twos;
        int max_two = -1e9;
        twos.push(nums[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < max_two) return true;
            while (!twos.empty() && nums[i] > twos.top()) {
                max_two = twos.top();
                twos.pop();
            }
            if (nums[i] > max_two) twos.push(nums[i]);
        }
        return false;
    }
};