#include "TreeNode.h"

class Solution {
public:
    bool flag = false;

    bool checkSubTree(TreeNode *t1, TreeNode *t2) {
        preorder(t1, t2);
        return flag;
    }

    void preorder(TreeNode *t1, TreeNode *t2) {
        if (!t1) return;
        if (t1->val == t2->val) {
            if (is_similar(t1, t2)) {
                flag = true;
                return;
            }
        }
        preorder(t1->left, t2);
        preorder(t1->right, t2);
    }

    bool is_similar(TreeNode *node1, TreeNode *node2) {
        if (!node2) return true;
        if (!node1) return false;
        if (node1->val != node2->val) return false;
        return is_similar(node1->left, node2->left) && is_similar(node1->right, node2->right);
    }
};