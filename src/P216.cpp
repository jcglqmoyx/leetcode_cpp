#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        for (int i = 0; i <= 9; i++) used.push_back(false);
        if (k > n) return {};
        dfs(0, k, 1, 0, n);
        return combinations;
    }

    void dfs(int count, int k, int cur, int sum, int n) {
        if (sum > n || count > k) return;
        if (sum == n && count == k) {
            combinations.push_back(combination);
            return;
        }
        for (int i = cur; i <= 9; i++) {
            if (!used[i]) {
                combination.push_back(i);
                used[i] = true;
                dfs(count + 1, k, i + 1, sum + i, n);
                combination.pop_back();
                used[i] = false;
            }
        }
    }

private:
    vector<vector<int>> combinations;
    vector<int> combination;
    vector<bool> used;
};