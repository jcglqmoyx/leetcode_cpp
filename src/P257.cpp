#include <vector>
#include <string>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> paths;
        dfs(root, "", paths);
        return paths;
    }

    void dfs(TreeNode *root, string cur, vector<string> &paths) {
        if (!root) {
            return;
        }
        if (!cur.empty()) {
            cur += "->" + to_string(root->val);
        } else {
            cur += to_string(root->val);
        }
        if (!root->left && !root->right) {
            paths.push_back(cur);
        }
        dfs(root->left, cur, paths);
        dfs(root->right, cur, paths);
    }
};