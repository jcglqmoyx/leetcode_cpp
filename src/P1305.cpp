#include <vector>
#include <algorithm>
#include "TreeNode.h"

using namespace std;

//class Solution {
//public:
//    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
//        vector<int> nums;
//        inorder(root1, nums);
//        inorder(root2, nums);
//        sort(nums.begin(), nums.end());
//        return nums;
//    }
//
//    void inorder(TreeNode *root, vector<int> &nums) {
//        if (!root) {
//            return;
//        }
//        nums.push_back(root->val);
//        inorder(root->left, nums);
//        inorder(root->right, nums);
//    }
//};

class Solution {
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);
        vector<int> nums;
        nums.reserve(arr1.size() + arr2.size());
        int i = 0, j = 0;
        while (i < arr1.size() || j < arr2.size()) {
            if (i < arr1.size() && j < arr2.size()) {
                if (arr1[i] < arr2[j]) nums.push_back(arr1[i++]);
                else nums.push_back(arr2[j++]);
            } else if (i < arr1.size()) nums.push_back(arr1[i++]);
            else nums.push_back(arr2[j++]);
        }
        return nums;
    }

    void inorder(TreeNode *root, vector<int> &nums) {
        if (!root) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};