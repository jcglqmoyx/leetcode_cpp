#include "TreeNode.h"

class Solution {
public:
    int ans = 1;

    int depth(TreeNode *node) {
        if (!node) return 0;
        int l = depth(node->left);
        int r = depth(node->right);
        if (l + r + 1 > ans) ans = l + r + 1;
        return l > r ? l + 1 : r + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        depth(root);
        return ans - 1;
    }
};