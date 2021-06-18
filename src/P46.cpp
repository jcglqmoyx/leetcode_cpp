#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permutations;
    vector<int> permutation;

    vector<vector<int>> permute(vector<int> &nums) {
        permutation = nums;
        backtrack(0);
        return permutations;
    }

    void backtrack(int cur) {
        if (cur == permutation.size()) permutations.push_back(permutation);
        for (int i = cur; i < permutation.size(); i++) {
            swap(permutation[i], permutation[cur]);
            backtrack(cur + 1);
            swap(permutation[i], permutation[cur]);
        }
    }
};