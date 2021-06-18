#include "TreeNode.h"

class Solution {
public:
    int res = 0;

    int countUnivalSubtrees(TreeNode *root) {
        if (!root) return 0;
        dfs(root);
        return res;
    }

    bool dfs(TreeNode *root) {
        if (!root->left && !root->right) {
            res++;
            return true;
        }
        bool flag = true;
        if (root->left && !(dfs(root->left) && root->val == root->left->val)) {
            flag = false;
        }
        if (root->right && !(dfs(root->right) && root->val == root->right->val)) {
            flag = false;
        }
        if (flag) {
            res++;
        } else {
            return false;
        }
        return true;
    }
};