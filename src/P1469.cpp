#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> lonely_nodes;

    vector<int> getLonelyNodes(TreeNode *root) {
        dfs(root);
        return lonely_nodes;
    }

    void dfs(TreeNode *node) {
        if (!node) return;
        if (!node->left && node->right) lonely_nodes.push_back(node->right->val);
        if (node->left && !node->right) lonely_nodes.push_back(node->left->val);
        dfs(node->left);
        dfs(node->right);
    }
};