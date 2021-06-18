#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) return false;
        int mn = INT32_MAX, mid = INT32_MAX;
        for (int num : nums) {
            if (num > mid && mid > mn) return true;
            if (num < mn) {
                mn = num;
            } else if (num > mn && num < mid) {
                mid = num;
            }
        }
        return false;
    }
};