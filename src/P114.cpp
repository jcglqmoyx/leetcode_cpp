//#include <vector>
//#include "TreeNode.h"
//
//using namespace std;
//
//class Solution {
//public:
//    void flatten(TreeNode *root) {
//        vector<TreeNode *> nodes;
//        preorder(root, nodes);
//        for (int i = 1; i < nodes.size(); i++) {
//            nodes[i]->left = nullptr;
//            nodes[i - 1]->right = nodes[i];
//        }
//    }
//
//    void preorder(TreeNode *root, vector<TreeNode *> &nodes) {
//        if (!root) return;
//        nodes.push_back(root);
//        preorder(root->left, nodes);
//        preorder(root->right, nodes);
//    }
//};


//#include <stack>
//#include "TreeNode.h"
//
//using namespace std;
//
//class Solution {
//public:
//    void flatten(TreeNode *root) {
//        if (!root) return;
//        stack<TreeNode *> nodes;
//        nodes.push(root);
//        TreeNode *prev = nullptr;
//        while (!nodes.empty()) {
//            TreeNode *node = nodes.top();
//            nodes.pop();
//            if (prev != nullptr) {
//                prev->left = nullptr;
//                prev->right = node;
//            }
//            if (node->right) nodes.push(node->right);
//            if (node->left) nodes.push(node->left);
//            prev = node;
//        }
//    }
//};



#include "TreeNode.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *left = cur->left, *predecessor = cur->left, *right = cur->right;
                while (predecessor && predecessor->right) {
                    predecessor = predecessor->right;
                }
                predecessor->right = right;
                cur->left = nullptr;
                cur->right = left;
            }
            cur = cur->right;
        }
    }
};