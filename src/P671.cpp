#include "TreeNode.h"

class Solution {
public:
    int first = 0, second = 0;

    int findSecondMinimumValue(TreeNode *root) {
        dfs(root);
        if (first != second && second != 0) {
            return second;
        } else {
            return -1;
        }
    }

    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }
        if (first == 0) {
            first = root->val;
        } else if (second == 0 && root->val != first) {
            second = root->val;
        }
        if (root->val < second) {
            if (root->val < first) {
                second = first;
                first = root->val;
            } else {
                if (first != root->val) {
                    second = root->val;
                }
            }
        }
        dfs(root->left);
        dfs(root->right);
    }
};