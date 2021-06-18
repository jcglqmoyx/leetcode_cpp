#include "Node.h"

class Solution {
public:
    vector<int> res;

    vector<int> postorder(Node *root) {
        dfs(root);
        return res;
    }

    void dfs(Node *root) {
        if (!root) {
            return;
        }
        for (Node *node : root->children) {
            dfs(node);
        }
        res.push_back(root->val);
    }
};