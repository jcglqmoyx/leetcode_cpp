#include "TreeNode.h"

class Solution {
public:
    int prev;

    bool isUnivalTree(TreeNode *root) {
        prev = root->val;
        return dfs(root);
    }

    bool dfs(TreeNode *root) {
        bool left = root->left == nullptr || dfs(root->left);
        bool right = root->right == nullptr || dfs(root->right);
        return root->val == prev && left && right;
    }
};