#include <vector>
#include <queue>
#include <cstdint>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> largest_values;
        if (!root) return largest_values;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int largest_value = INT32_MIN;
            for (int i = nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                largest_value = max(largest_value, node->val);
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
            largest_values.push_back(largest_value);
        }
        return largest_values;
    }
};