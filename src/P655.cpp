#include <vector>
#include <string>
#include <cmath>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    int n, m;

    int get_height(TreeNode *root) {
        if (!root) return 0;
        int left = get_height(root->left) + 1;
        int right = get_height(root->right) + 1;
        return max(left, right);
    }

    void dfs(TreeNode *root, int r, int c) {
        if (!root) return;
        res[r][c] = to_string(root->val);
        dfs(root->left, r + 1, c - (int) pow(2, n - r - 2));
        dfs(root->right, r + 1, c + (int) pow(2, n - r - 2));
    }

    vector<vector<string>> printTree(TreeNode *root) {
        n = get_height(root), m = (int) pow(2, n) - 1;
        res.resize(n, vector<string>(m));
        res[0][(m - 1) / 2] = to_string(root->val);
        dfs(root->left, 1, (m - 1) / 2 - (int) pow(2, n - 2));
        dfs(root->right, 1, (m - 1) / 2 + (int) pow(2, n - 2));
        return res;
    }
};