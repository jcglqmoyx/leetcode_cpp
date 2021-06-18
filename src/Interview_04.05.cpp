#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> nums;

    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        inorder(root);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1]) return false;
        }
        return true;
    }

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
};