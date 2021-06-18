#include <unordered_set>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    unordered_set<int> set;
    bool flag = false;

    bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
        inorder(root2);
        query(root1, target);
        return flag;
    }

    void query(TreeNode *root, int target) {
        if (!root) return;
        if (set.find(target - root->val) != set.end()) {
            flag = true;
            return;
        }
        query(root->left, target);
        query(root->right, target);
    }

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        set.insert(root->val);
        inorder(root->right);
    }
};