#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int res;
    int n;

    int kthLargest(TreeNode *root, int k) {
        n = k;
        dfs(root);
        return res;
    }

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->right);
        n--;
        if (n == 0) {
            res = root->val;
            return;
        }
        dfs(root->left);
    }
};