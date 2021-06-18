#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> res;

    vector<int> inorderTraversal(TreeNode *root) {
        inorder(root);
        return res;
    }

    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
};