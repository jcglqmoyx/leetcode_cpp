#include "TreeNode.h"

class Solution {
public:
    int tilt = 0;

    int findTilt(TreeNode *root) {
        traverse(root);
        return tilt;
    }

    int traverse(TreeNode *node) {
        if (!node) return 0;
        int l = traverse(node->left);
        int r = traverse(node->right);
        tilt += l > r ? l - r : r - l;
        return l + r + node->val;
    }
};