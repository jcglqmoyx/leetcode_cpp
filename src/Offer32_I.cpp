#include "TreeNode.h"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> levelOrder(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            for (int i = (int) nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                res.push_back(node->val);
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
        }
        return res;
    }
};