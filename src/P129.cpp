#include "TreeNode.h"

class Solution {
public:
    int sum = 0;

    int sumNumbers(TreeNode *root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode *root, int num) {
        if (!root) return;
        num = num * 10 + root->val;
        if (is_leaf(root)) sum += num;
        dfs(root->left, num);
        dfs(root->right, num);
    }

    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }
};