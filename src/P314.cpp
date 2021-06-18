#include <vector>
#include <map>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        if (!root) return {};
        map<int, vector<int>> m;
        queue<pair<TreeNode *, int>> nodes;
        nodes.push({root, 0});
        while (!nodes.empty()) {
            auto[node, offset] = nodes.front();
            nodes.pop();
            m[offset].push_back(node->val);
            if (node->left) {
                nodes.push({node->left, offset - 1});
            }
            if (node->right) {
                nodes.push({node->right, offset + 1});
            }
        }
        vector<vector<int>> res;
        res.reserve(m.size());
        for (auto &x : m) {
            res.push_back(x.second);
        }
        return res;
    }
};