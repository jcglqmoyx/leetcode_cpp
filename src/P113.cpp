#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> arr;
        dfs(root, 0, sum, res, arr);
        return res;
    }

    void dfs(TreeNode *node, int cur, int sum, vector<vector<int>> &res, vector<int> arr) {
        if (!node) return;
        arr.push_back(node->val);
        if (is_leaf(node) && cur + node->val == sum) {
            res.push_back(arr);
            return;
        }
        dfs(node->left, cur + node->val, sum, res, arr);
        dfs(node->right, cur + node->val, sum, res, arr);
    }

    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }
};