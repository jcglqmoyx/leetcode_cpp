#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        dfs(root, {}, sum);
        return res;
    }

    void dfs(TreeNode *node, vector<int> arr, int sum) {
        if (!node) return;
        if (is_leaf(node) && sum == node->val) {
            arr.push_back(node->val);
            res.push_back(arr);
            return;
        }
        arr.push_back(node->val);
        dfs(node->left, arr, sum - node->val);
        dfs(node->right, arr, sum - node->val);
    }

    bool is_leaf(TreeNode *node) {
        return !node->left && !node->right;
    }
};