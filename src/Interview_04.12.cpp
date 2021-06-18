#include "TreeNode.h"

class Solution {
public:
    int paths = 0;

    int pathSum(TreeNode *root, int sum) {
        preorder(root, sum);
        return paths;
    }

    void preorder(TreeNode *node, int sum) {
        if (!node) return;
        dfs(node, sum);
        preorder(node->left, sum);
        preorder(node->right, sum);
    }

    void dfs(TreeNode *root, int sum) {
        if (!root) {
            return;
        }
        if (root->val == sum) {
            paths++;
        }
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};