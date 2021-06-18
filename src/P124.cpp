#include "TreeNode.h"

class Solution {
public:
    int max_sum = -1e9;

    int maxPathSum(TreeNode *root) {
        dfs(root);
        return max_sum;
    }

    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l = max(dfs(root->left), 0), r = max(dfs(root->right), 0);
        max_sum = max(max_sum, root->val + l + r);
        return root->val + max(l, r);
    }
};