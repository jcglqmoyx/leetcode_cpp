#include "TreeNode.h"

class Solution {
public:
    TreeNode *target_copy;

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        dfs(original, cloned, target);
        return target_copy;
    }

    void dfs(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (!original) {
            return;
        }
        if (original == target) {
            target_copy = cloned;
            return;
        }
        dfs(original->left, cloned->left, target);
        dfs(original->right, cloned->right, target);
    }
};