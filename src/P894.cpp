#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<TreeNode *> allPossibleFBT(int n) {
        if (n == 0) return {};
        if (n == 1) return {new TreeNode(0)};
        vector<TreeNode *> res;
        for (int i = 1; i < n; i += 2) {
            int j = n - i - 1;
            for (auto left : allPossibleFBT(i)) {
                for (auto right : allPossibleFBT(j)) {
                    auto *node = new TreeNode(0);
                    node->left = left;
                    node->right = right;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};