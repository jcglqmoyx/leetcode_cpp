#include "TreeNode.h"

class Solution {
public:
    int max_depth = 0;

    int maxDepth(TreeNode *root) {
        dfs(root, 1);
        return max_depth;
    }

    void dfs(TreeNode *root, int depth) {
        if (!root) return;
        if (depth > max_depth) max_depth = depth;
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};