#include "TreeNode.h"

class Solution {
public:
    int count = 0;
    int res = 0;

    int kthSmallest(TreeNode *root, int k) {
        inorder(root, k);
        return res;
    }

    void inorder(TreeNode *root, int k) {
        if (!root) return;
        inorder(root->left, k);
        count++;
        if (count == k) {
            res = root->val;
            return;
        }
        inorder(root->right, k);
    }
};