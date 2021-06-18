#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> t;
        vector<vector<int>> res;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            t.clear();
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            res.push_back(t);
        }
        return res;
    }
};

class Solution1 {
public:
    vector<int> t;
    vector<vector<int>> res;

    void dfs(int cur, vector<int> nums) {
        if (cur == nums.size()) {
            res.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        dfs(0, nums);
        return res;
    }
};