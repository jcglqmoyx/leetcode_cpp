#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode *root) {
        dfs(root);
        return leaves;
    }

    int dfs(TreeNode *root) {
        if (!root) return -1;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int depth = max(l, r) + 1;
        if (depth >= leaves.size()) leaves.emplace_back();
        leaves[depth].push_back(root->val);
        return depth;
    }

private:
    vector<vector<int>> leaves;
};