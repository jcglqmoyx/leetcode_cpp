#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }

    vector<TreeNode *> generate(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode *> nodes;
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> left_nodes = generate(start, i - 1);
            vector<TreeNode *> right_nodes = generate(i + 1, end);
            for (TreeNode *left_node : left_nodes) {
                for (TreeNode *right_node : right_nodes) {
                    auto *node = new TreeNode(i);
                    node->left = left_node;
                    node->right = right_node;
                    nodes.push_back(node);
                }
            }
        }
        return nodes;
    }
};