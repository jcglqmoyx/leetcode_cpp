#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *findNearestRightNode(TreeNode *root, TreeNode *u) {
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int size = nodes.size();
            for (int i = size; i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node == u) {
                    if (i == 1) {
                        return nullptr;
                    } else {
                        return nodes.front();
                    }
                }
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
        }
        return nullptr;
    }
};