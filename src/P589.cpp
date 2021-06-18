#include "Node.h"

class Solution {
public:
    vector<int> res;

    vector<int> preorder(Node *root) {
        dfs(root);
        return res;
    }

    void dfs(Node *root) {
        if (!root) {
            return;
        }
        res.push_back(root->val);
        if (!root->children.empty()) {
            for (Node *node : root->children) {
                dfs(node);
            }
        }
    }
};