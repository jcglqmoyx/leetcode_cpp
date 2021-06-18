#include <unordered_map>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    unordered_map<int, int> cnt;
    int res = 0;

    int pathSum(TreeNode *root, int targetSum) {
        cnt[0] = 1;
        dfs(root, targetSum, 0);
        return res;
    }

    void dfs(TreeNode *root, int target, int cur) {
        if (!root) return;
        cur += root->val;
        res += cnt[cur - target];
        cnt[cur]++;
        dfs(root->left, target, cur);
        dfs(root->right, target, cur);
        cnt[cur]--;
    }
};