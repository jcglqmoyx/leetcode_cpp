#include "TreeNode.h"

class Solution {
public:
    bool flag = false;

    bool isSubtree(TreeNode *s, TreeNode *t) {
        dfs(s, t);
        return flag;
    }

    void dfs(TreeNode *s, TreeNode *t) {
        if (!s) {
            return;
        }
        bool is_subtree = cmp(s, t);
        if (is_subtree) {
            flag = true;
        }
        dfs(s->left, t);
        dfs(s->right, t);
    }

    bool cmp(TreeNode *s, TreeNode *t) {
        if (!s && !t) {
            return true;
        } else if (!s || !t || s->val != t->val) {
            return false;
        }
        return cmp(s->left, t->left) && cmp(s->right, t->right);
    }
};