#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    bool isEvenOddTree(TreeNode *root) {
        queue<TreeNode *> nodes;
        nodes.push(root);
        bool even = true;
        while (!nodes.empty()) {
            int prev = 0;
            for (int i = nodes.size(); i > 0; i--) {
                TreeNode *cur = nodes.front();
                nodes.pop();
                if (even && cur->val % 2 == 0 || !even && cur->val % 2 == 1) return false;
                if (cur->left) nodes.push(cur->left);
                if (cur->right) nodes.push(cur->right);
                if (even && prev && prev >= cur->val || !even && prev && prev <= cur->val) return false;
                prev = cur->val;
            }
            even = !even;
        }
        return true;
    }
};