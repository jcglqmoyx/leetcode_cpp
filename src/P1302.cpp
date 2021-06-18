#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        queue<TreeNode *> nodes;
        nodes.push(root);
        int sum = 0;
        while (!nodes.empty()) {
            sum = 0;
            for (int i = (int) nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                sum += node->val;
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }
        }
        return sum;
    }
};