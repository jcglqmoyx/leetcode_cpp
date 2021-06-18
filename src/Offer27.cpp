#include "TreeNode.h"

class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (!root) return nullptr;
        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};