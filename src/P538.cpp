#include "TreeNode.h"

class Solution {
public:
    int prev = -10001;

    TreeNode *convertBST(TreeNode *root) {
        inorder(root);
        return root;
    }

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->right);
        if (prev != -10001) {
            root->val += prev;
        }
        prev = root->val;
        inorder(root->left);
    }
};