#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *dummy = new TreeNode(0), *cur = dummy;

    TreeNode *convertBiNode(TreeNode *root) {
        inorder(root);
        return dummy->right;
    }

    void inorder(TreeNode *node) {
        if (!node) return;
        inorder(node->left);
        node->left = nullptr;
        cur->right = node;
        cur = cur->right;
        inorder(node->right);
    }
};