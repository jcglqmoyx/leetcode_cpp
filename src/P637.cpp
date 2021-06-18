#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            double sum = 0;
            int size = (int) nodes.size();
            for (int i = size; i > 0; i--) {
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
            res.push_back(sum / size);
        }
        return res;
    }
};