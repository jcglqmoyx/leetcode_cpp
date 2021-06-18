#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> nodes;
        nodes.push(root);
        int bottom_left_value = 0;
        while (!nodes.empty()) {
            bottom_left_value = nodes.front()->val;
            for (int i = (int) nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }
        }
        return bottom_left_value;
    }
};