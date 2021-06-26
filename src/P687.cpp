#include "TreeNode.h"

class Solution {
public:
    int res = 0;

    int longestUnivaluePath(TreeNode *root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if (!root->left || root->val != root->left->val) l = 0;
        if (!root->right || root->val != root->right->val) r = 0;
        res = max(res, l + r);
        return max(l, r) + 1;
    }
};