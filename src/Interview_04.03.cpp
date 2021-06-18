#include <vector>
#include <queue>
#include "ListNode.h"
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        if (!tree) return {};
        vector<ListNode *> res;
        queue<TreeNode *> nodes;
        nodes.push(tree);
        while (!nodes.empty()) {
            auto *list = new ListNode(0), *dummy = list;
            for (int i = nodes.size(); i > 0; i--) {
                TreeNode *node = nodes.front();
                nodes.pop();
                list->next = new ListNode(node->val);
                list = list->next;
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
            res.push_back(dummy->next);
        }
        return res;
    }
};