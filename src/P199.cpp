#include "TreeNode.h"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            res.push_back(nodes.back()->val);
            for (int i = (int) nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
        }
        return res;
    }
};