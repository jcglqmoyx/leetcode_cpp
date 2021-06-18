#include "TreeNode.h"

class Solution {
public:
    TreeNode *prev = new TreeNode(0);
    TreeNode *res = prev;

    TreeNode *increasingBST(TreeNode *root) {
        inorder(root);
        return res->right;
    }

    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        root->left = nullptr;
        prev->right = root;
        prev = prev->right;
        inorder(root->right);
    }
};