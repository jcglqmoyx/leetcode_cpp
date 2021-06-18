#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return combinations;
    }

private:
    void dfs(vector<int> &candidates, int target, int index) {
        if (target == 0) {
            combinations.emplace_back(combination);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] <= target) {
                combination.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i + 1);
                combination.pop_back();
            } else break;
        }
    }

    vector<vector<int>> combinations;
    vector<int> combination;
};