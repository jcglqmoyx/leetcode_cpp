#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        return construct(preorder, 0, (int) preorder.size() - 1);
    }

    TreeNode *construct(vector<int> &preorder, int left, int right) {
        if (left > right) return nullptr;
        auto *root = new TreeNode(preorder[left]);
        int pivot = left + 1;
        while (pivot <= right && preorder[left] > preorder[pivot]) {
            pivot++;
        }
        root->left = construct(preorder, left + 1, pivot - 1);
        root->right = construct(preorder, pivot, right);
        return root;
    }
};