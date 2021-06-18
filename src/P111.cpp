#include <algorithm>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int min_depth = 100000;

    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        dfs(root, 1);
        return min_depth;
    }

    void dfs(TreeNode *root, int depth) {
        if (!root) {
            return;
        }
        if (is_leaf(root)) {
            min_depth = min(min_depth, depth);
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }
};