#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinations;
    vector<int> combination;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtrack(candidates, target, 0);
        return combinations;
    }

    void backtrack(vector<int> &candidates, int target, int index) {
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }
        if (index == candidates.size() || target < 0) return;
        backtrack(candidates, target, index + 1);
        combination.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], index);
        combination.pop_back();
    }
};