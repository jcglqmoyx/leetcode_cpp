#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    vector<Node *> dfs(Node *node) {
        Node *cur = node, *tail = node;
        while (cur) {
            tail = cur;
            if (cur->child) {
                auto t = dfs(cur->child);
                cur->child = nullptr;
                Node *next = cur->next;
                t[1]->next = next;
                if (next) next->prev = t[1];
                cur->next = t[0];
                t[0]->prev = cur;
                cur = cur->next;
                tail = t[1];
            } else {
                cur = cur->next;
            }
        }
        return {node, tail};
    }

    Node *flatten(Node *head) {
        return dfs(head)[0];
    }
};