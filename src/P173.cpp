#include <stack>

#include "TreeNode.h"

using namespace std;

class BSTIterator {
public:
    stack<TreeNode *> stk;

    BSTIterator(TreeNode *root) {
        leftmost_inorder(root);
    }

    void leftmost_inorder(TreeNode *node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }

    int next() {
        TreeNode *head = stk.top();
        stk.pop();
        if (head->right) {
            leftmost_inorder(head->right);
        }
        return head->val;
    }

    bool hasNext() {
        return !stk.empty();
    }
};