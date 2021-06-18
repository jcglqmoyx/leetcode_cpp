#include "TreeNode.h"

class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (p->right) return min_node(p->right);
        TreeNode *successor = nullptr;
        while (root != p) {
            if (root->val > p->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if (!successor) return min_node(p->right);
        return successor;
    }

    TreeNode *min_node(TreeNode *node) {
        TreeNode *p = node;
        while (p && p->left) {
            p = p->left;
        }
        return p;
    }
};