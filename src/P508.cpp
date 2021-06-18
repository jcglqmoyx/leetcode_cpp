#include <vector>
#include <unordered_map>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    unordered_map<int, int> cnt;

    vector<int> findFrequentTreeSum(TreeNode *root) {
        vector<int> res;
        dfs(root);
        int ans = 0;
        for (auto &x : cnt) {
            ans = max(ans, x.second);
        }
        for (auto &x : cnt) {
            if (x.second == ans) {
                res.push_back(x.first);
            }
        }
        return res;
    }

    int dfs(TreeNode *root) {
        int l = 0, r = 0;
        if (root->left) l = dfs(root->left);
        if (root->right) r = dfs(root->right);
        int sum = l + r + root->val;
        cnt[sum]++;
        return sum;
    }
};