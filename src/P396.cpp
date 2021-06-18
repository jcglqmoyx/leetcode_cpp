#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int> &nums) {
        long sum = 0;
        long val = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            val += i * nums[i];
        }
        long max_value = val;
        for (int i = 1; i < n; i++) {
            long temp = val - sum + (long) nums[(i + n - 1) % n] * n;
            max_value = max(max_value, temp);
            val = temp;
        }
        return (int) max_value;
    }
};