#include <queue>
#include <unordered_set>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *correctBinaryTree(TreeNode *root) {
        queue<TreeNode *> nodes;
        nodes.push(root);
        unordered_set<TreeNode *> set;
        while (!nodes.empty()) {
            set.clear();
            for (int i = nodes.size(); i; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node->right) {
                    if (set.count(node->right->right)) {
                        node->right = nullptr;
                        return root;
                    } else {
                        nodes.push(node->right);
                        set.insert(node->right);
                    }
                }
                if (node->left) {
                    if (set.count(node->left->right)) {
                        node->left = nullptr;
                        return root;
                    } else {
                        nodes.push(node->left);
                        set.insert(node->left);
                    }
                }
            }
        }
        return root;
    }
};