#include "TreeNode.h"

class Solution {
public:
    TreeNode *res;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return res;
    }

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (res || root == nullptr) return false;
        bool l = dfs(root->left, p, q);
        bool r = dfs(root->right, p, q);
        if (l && r || (l || r) && (root == p || root == q)) {
            res = root;
        }
        return l || r || root == p || root == q;
    }
};