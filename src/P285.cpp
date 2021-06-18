#include "TreeNode.h"

class Solution {
public:
    bool flag = false;
    TreeNode *successor = nullptr;

    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        inorder(root, p);
        return successor;
    }

    void inorder(TreeNode *node, TreeNode *p) {
        if (!node) return;
        inorder(node->left, p);
        if (flag) {
            successor = node;
            flag = false;
            return;
        }
        if (p == node) {
            flag = true;
        }
        inorder(node->right, p);
    }
};