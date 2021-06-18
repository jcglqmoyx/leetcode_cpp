#include "TreeNode.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return traverse(root->left, root->right);
    }

    bool traverse(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        } else if (!left || !right) {
            return false;
        } else {
            if (left->val != right->val) {
                return false;
            }
        }
        return traverse(left->left, right->right) && traverse(left->right, right->left);
    }
};