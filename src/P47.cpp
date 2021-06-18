#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permutations;
    vector<int> permutation;
    vector<bool> visited;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        visited.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return permutations;
    }

    void backtrack(vector<int> &nums, int idx) {
        if (idx == nums.size()) {
            permutations.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            permutation.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, idx + 1);
            permutation.pop_back();
            visited[i] = false;
        }
    }
};