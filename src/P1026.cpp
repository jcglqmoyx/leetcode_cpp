#include "TreeNode.h"

class Solution {
public:
    int res = 0;

    int maxAncestorDiff(TreeNode *root) {
        dfs(root->val, root->val, root);
        return res;
    }

    void dfs(int mn, int mx, TreeNode *node) {
        if (!node) return;
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        res = max(res, mx - mn);
        dfs(mn, mx, node->left);
        dfs(mn, mx, node->right);
    }
};