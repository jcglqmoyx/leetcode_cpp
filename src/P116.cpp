#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

//class Solution {
//public:
//    Node *connect(Node *root) {
//        if (!root) return nullptr;
//        queue<Node *> q;
//        q.push(root);
//        while (!q.empty()) {
//            for (int i = q.size(); i > 0; i--) {
//                Node *node = q.front();
//                q.pop();
//                if (i > 1) {
//                    node->next = q.front();
//                } else {
//                    node->next = nullptr;
//                }
//                if (node->left) q.push(node->left);
//                if (node->right) q.push(node->right);
//            }
//        }
//        return root;
//    }
//};

class Solution {
public:
    Node *connect(Node *root) {
        if (!root) return nullptr;
        Node *left_most = root;
        while (left_most->left) {
            Node *node = left_most;
            while (node) {
                node->left->next = node->right;
                if (node->next) node->right->next = node->next->left;
                node = node->next;
            }
            left_most = left_most->left;
        }
        return root;
    }
};