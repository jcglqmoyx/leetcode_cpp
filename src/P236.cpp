#include "TreeNode.h"

class Solution {
public:
    TreeNode *ans;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return false;
        bool l_son = dfs(root->left, p, q);
        bool r_son = dfs(root->right, p, q);
        if (l_son && r_son || (root == p || root == q) && (l_son || r_son)) ans = root;
        return l_son || r_son || root == p || root == q;
    }
};