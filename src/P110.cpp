#include "TreeNode.h"

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return dfs(root) >= 0;
    }

    int dfs(TreeNode *node) {
        if (!node) return 0;
        int left_height, right_height;
        if ((left_height = dfs(node->left)) == -1 || (right_height = dfs(node->right)) == -1 ||
            abs(left_height - right_height) > 1)
            return -1;
        return max(left_height, right_height) + 1;
    }
};