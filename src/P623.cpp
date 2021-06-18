#include "TreeNode.h"
#include <queue>

using namespace std;

class Solution {
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (depth == 1) {
            auto *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        int d = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (d < depth) {
            d++;
            for (int i = q.size(); i > 0; i--) {
                auto t = q.front();
                q.pop();
                if (d < depth) {
                    if (t->left) q.push(t->left);
                    if (t->right) q.push(t->right);
                } else {
                    auto l = new TreeNode(val);
                    l->left = t->left;
                    t->left = l;
                    q.push(l);
                    auto r = new TreeNode(val);
                    r->right = t->right;
                    t->right = r;
                    q.push(r);
                }
            }
            if (d == depth) break;
        }
        return root;
    }
};