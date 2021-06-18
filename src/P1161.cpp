#include <queue>
#include <cstdint>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int maxLevelSum(TreeNode *root) {
        int level = 0;
        int res = 0;
        int max_sum = INT32_MIN;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            level++;
            int sum = 0;
            for (int i = nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
                sum += node->val;
            }
            if (sum > max_sum) {
                max_sum = sum;
                res = level;
            }
        }
        return res;
    }
};