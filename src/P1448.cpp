#include "TreeNode.h"

class Solution {
public:
    int count = 0;

    int goodNodes(TreeNode *root) {
        dfs(root, -10000);
        return count;
    }

    void dfs(TreeNode *node, int max_ancestor) {
        if (!node) return;
        if (node->val >= max_ancestor) {
            max_ancestor = node->val;
            count++;
        }
        dfs(node->left, max_ancestor);
        dfs(node->right, max_ancestor);
    }
};