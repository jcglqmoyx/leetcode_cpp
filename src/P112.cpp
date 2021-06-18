#include "TreeNode.h"

class Solution {
public:
    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }

    bool flag = false;

    bool hasPathSum(TreeNode *root, int sum) {
        dfs(root, sum);
        return flag;
    }

    void dfs(TreeNode *root, int left) {
        if (!root) {
            return;
        }
        if (is_leaf(root) && left - root->val == 0) {
            flag = true;
            return;
        }
        if (root->left) {
            dfs(root->left, left - root->val);
        }
        if (root->right) {
            dfs(root->right, left - root->val);
        }
    }
};