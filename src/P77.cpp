#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinations;
    vector<int> combination;

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return combinations;
    }

    void backtrack(int cur, int n, int k) {
        if (combination.size() + n - cur + 1 < k) return;
        if (combination.size() == k) {
            combinations.push_back(combination);
            return;
        }
        combination.push_back(cur);
        backtrack(cur + 1, n, k);
        combination.pop_back();
        backtrack(cur + 1, n, k);
    }
};