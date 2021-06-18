#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return construct(nums, 0, (int) nums.size() - 1);
    }

    TreeNode *construct(const vector<int> &nums, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        int mid = low + (high - low) / 2;
        auto *node = new TreeNode(nums[mid]);
        node->left = construct(nums, low, mid - 1);
        node->right = construct(nums, mid + 1, high);
        return node;
    }
};