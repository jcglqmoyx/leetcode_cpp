#include "TreeNode.h"
#include <vector>
#include <unordered_set>

using namespace std;

//class Solution {
//public:
//    vector<TreeNode *> arr;
//
//    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
//        unordered_set<int> del_set;
//        for (int n : to_delete) del_set.insert(n);
//        if (!del_set.count(root->val) && root->val != 0) arr.push_back(root);
//        dfs(root, del_set);
//        return arr;
//    }
//
//    void dfs(TreeNode *node, const unordered_set<int> &del_set) {
//        if (!node) return;
//        dfs(node->left, del_set);
//        dfs(node->right, del_set);
//        if (node->left && node->left->val == 0) node->left = nullptrptr;
//        if (node->right && node->right->val == 0) node->right = nullptrptr;
//        if (del_set.count(node->val)) {
//            if (node->left) arr.push_back(node->left);
//            if (node->right) arr.push_back(node->right);
//            node->val = 0;
//        }
//    }
//};

class Solution {
public:
    unordered_set<int> st;
    vector<TreeNode *> ans;

    TreeNode *post(TreeNode *t) {
        if (!t) return nullptr;
        TreeNode *tl = post(t->left), *tr = post(t->right);
        t->left = tl, t->right = tr;
        if (st.count(t->val)) {
            if (tl) ans.emplace_back(tl);
            if (tr) ans.emplace_back(tr);
            return nullptr;
        }
        return t;
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        for (auto &x : to_delete) st.insert(x);
        if (!st.count(root->val)) ans.emplace_back(root);
        post(root);
        return ans;
    }
};