#include <vector>
#include <queue>
#include "Node.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> row;
            for (int i = q.size(); i > 0; i--) {
                Node *node = q.front();
                q.pop();
                row.push_back(node->val);
                for (Node *child : node->children) {
                    q.push(child);
                }
            }
            res.push_back(row);
        }
        return res;
    }
};