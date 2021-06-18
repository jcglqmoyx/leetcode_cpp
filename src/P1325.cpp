#include "TreeNode.h"

class Solution {
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        if (!root) return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (is_leaf(root) && root->val == target) return nullptr;
        return root;
    }

    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }
};