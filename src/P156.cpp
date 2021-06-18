struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//class Solution {
//public:
//    TreeNode *upsideDownBinaryTree(TreeNode *root) {
//        if (!root || !root->left && !root->right) return root;
//        TreeNode *left = root->left, *right = root->right;
//        TreeNode *flipped_left = upsideDownBinaryTree(left);
//        left->left = right;
//        left->right = root;
//        root->left = nullptr;
//        root->right = nullptr;
//        return flipped_left;
//    }
//};

class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        TreeNode *tmp = nullptr;
        while (cur) {
            auto next = cur->left;
            cur->left = tmp; // copy original right to left
            tmp = cur->right; // save next level original right
            cur->right = pre; // copy original root to right
            pre = cur; // save cur root, i.e: next level left
            cur = next;
        }
        return pre;
    }
};