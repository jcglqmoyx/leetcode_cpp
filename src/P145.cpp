#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> res;

    vector<int> postorderTraversal(TreeNode *root) {
        postorder(root);
        return res;
    }

    void postorder(TreeNode *root) {
        if (!root) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        res.push_back(root->val);
    }
};