#include "TreeNode.h"

class Solution {
public:
    int sum = 0;

    int rangeSumBST(TreeNode *root, int low, int high) {
        inorder(root, low, high);
        return sum;
    }

    void inorder(TreeNode *root, int low, int high) {
        if (!root) {
            return;
        }
        inorder(root->left, low, high);
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }
        inorder(root->right, low, high);
    }
};