#include <string>
#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<string> strings;

    string smallestFromLeaf(TreeNode *root) {
        dfs(root, nullptr, "");

        string res;
        for (auto &s : strings) {
            reverse(s.begin(), s.end());
            if (res.empty()) res = s;
            res = min(res, s);
        }
        return res;
    }

    void dfs(TreeNode *node, TreeNode *parent, string s) {
        if (!node) {
            if (!parent->left && !parent->right) strings.push_back(s);
            return;
        }
        s.push_back(node->val + 'a');
        dfs(node->left, node, s);
        dfs(node->right, node, s);
    }
};