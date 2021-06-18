#include <unordered_map>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    unordered_map<TreeNode *, int> f, g;

    int rob(TreeNode *root) {
        postorder(root);
        return max(f[root], g[root]);
    }

    void postorder(TreeNode *node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }
};