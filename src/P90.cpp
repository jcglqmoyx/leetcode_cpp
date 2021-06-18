#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets;
    vector<int> subset;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return subsets;
    }

    void dfs(vector<int> &nums, int index) {
        subsets.push_back(subset);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            dfs(nums, i + 1);
            subset.pop_back();
        }
    }
};