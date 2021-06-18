#include <unordered_map>
#include <string>
#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    unordered_map<string, int> ids;
    unordered_map<int, int> map;
    vector<TreeNode *> ans;
    int cnt = 0;

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode *node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        string key = to_string(node->val) + ' ' + to_string(left) + ' ' + to_string(right);
        if (ids.find(key) == ids.end()) {
            ids[key] = ++cnt;
        }
        int id = ids[key];
        if (++map[id] == 2) ans.push_back(node);
        return id;
    }
};