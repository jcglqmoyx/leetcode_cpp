#include <cstdint>
#include <algorithm>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int min_diff = INT32_MAX;
    TreeNode *prev = nullptr;

    int minDiffInBST(TreeNode *root) {
        inorder(root);
        return min_diff;
    }

    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        if (prev != nullptr) {
            min_diff = min(min_diff, root->val - prev->val);
            if (min_diff == 1) {
                return;
            }
        }
        prev = root;
        inorder(root->right);
    }
};