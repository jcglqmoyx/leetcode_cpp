#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nums1, nums2;

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        dfs(root1, nums1);
        dfs(root2, nums2);
        if (nums1.size() != nums2.size()) {
            return false;
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] != nums2[i]) {
                return false;
            }
        }
        return true;
    }

    void dfs(TreeNode *root, vector<int> &nums) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            nums.push_back(root->val);
        }
        dfs(root->left, nums);
        dfs(root->right, nums);
    }
};