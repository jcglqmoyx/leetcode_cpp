#include "TreeNode.h"

class Solution {
public:
    int prev = 0;

    TreeNode *bstToGst(TreeNode *root) {
        inorder(root);
        return root;
    }

    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->right);
        root->val += prev;
        prev = root->val;
        inorder(root->left);
    }
};