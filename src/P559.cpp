#include "Node.h"

class Solution {
public:
    int max_depth = 0;

    int maxDepth(Node *root) {
        dfs(root, 1);
        return max_depth;
    }

    void dfs(Node *root, int depth) {
        if (!root) {
            return;
        }
        max_depth = max(max_depth, depth);
        for (Node *child : root->children) {
            dfs(child, depth + 1);
        }
    }
};