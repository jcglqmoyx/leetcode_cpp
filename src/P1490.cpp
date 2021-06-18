#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    unordered_map<Node *, Node *> map;

    Node *cloneTree(Node *root) {
        if (!root) return nullptr;
        if (map.count(root)) return map[root];
        Node *node = new Node(root->val);
        map[root] = node;
        for (Node *child : root->children) {
            node->children.push_back(cloneTree(child));
        }
        return node;
    }
};