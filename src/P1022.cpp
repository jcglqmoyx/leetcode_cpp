#include "TreeNode.h"

class Solution {
public:
    int ans = 0;

    int sumRootToLeaf(TreeNode *root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode *node, int cur) {
        if (!node) return;
        if (!node->left && !node->right) {
            ans += (cur << 1) + node->val;
        }
        dfs(node->left, cur * 2 + node->val);
        dfs(node->right, cur * 2 + node->val);
    }
};