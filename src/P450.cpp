#include "TreeNode.h"

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode *t = root;
            root = min_node(t->right);
            root->right = delete_min(t->right);
            root->left = t->left;
        }
        return root;
    }

    TreeNode *min_node(TreeNode *node) {
        if (!node->left) return node;
        return min_node(node->left);
    }

    TreeNode *delete_min(TreeNode *node) {
        if (!node->left) return node->right;
        node->left = delete_min(node->left);
        return node;
    }
};