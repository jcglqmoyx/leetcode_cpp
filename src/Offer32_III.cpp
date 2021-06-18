#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) return {};
        vector<vector<int>> res;
        bool flag = false;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            vector<int> row;
            for (int i = nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                row.push_back(node->val);
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
            if (flag) reverse(row.begin(), row.end());
            flag = !flag;
            res.push_back(row);
        }
        return res;
    }
};