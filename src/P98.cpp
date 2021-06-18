#include "TreeNode.h"

class Solution {
public:
    bool flag = true;
    long long prev = -2147483649;

    bool isValidBST(TreeNode *root) {
        inorder(root);
        return flag;
    }

    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        if (prev != -2147483649) {
            if (root->val <= prev) {
                flag = false;
                return;
            }
        }
        prev = root->val;
        inorder(root->right);
    }
};