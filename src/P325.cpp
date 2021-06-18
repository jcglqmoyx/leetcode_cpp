#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        int res = 0;
        if (nums[0] == k) res = 1;
        map[nums[0]] = 0;
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
            if (map.find(nums[i]) == map.end()) map[nums[i]] = i;
            if (nums[i] == k) res = max(res, i + 1);
            else if (map.find(nums[i] - k) != map.end()) res = max(res, i - map[nums[i] - k]);
        }
        return res;
    }
};