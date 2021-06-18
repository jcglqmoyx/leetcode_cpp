#include "TreeNode.h"
#include <unordered_set>

using namespace std;

class FindElements {
public:
    unordered_set<int> nums;

    FindElements(TreeNode *root) {
        recover(root->left, 1);
        recover(root->right, 2);
    }

    void recover(TreeNode *root, int val) {
        if (!root) return;
        root->val = val;
        nums.insert(val);
        recover(root->left, 2 * val + 1);
        recover(root->right, 2 * val + 2);
    }

    bool find(int target) {
        return nums.count(target);
    }
};