#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;

    void backtrack(int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[cur]);
        backtrack(cur + 1, nums);
        subset.pop_back();
        backtrack(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        backtrack(0, nums);
        return res;
    }
};