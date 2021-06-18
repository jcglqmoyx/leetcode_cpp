#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> res;

    vector<int> preorderTraversal(TreeNode *root) {
        preorder(root);
        return res;
    }

    void preorder(TreeNode *root) {
        if (!root) {
            return;
        }
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};