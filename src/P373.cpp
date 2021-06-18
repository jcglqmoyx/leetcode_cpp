#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x, y;

    Node(int _x, int _y) : x(_x), y(_y) {}
};

bool operator<(Node a, Node b) {
    return a.x + a.y > b.x + b.y;
}

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<vector<int>> res;
        priority_queue<Node> q;
        for (int i : nums1) {
            for (int j : nums2) {
                q.push(Node(i, j));
            }
        }
        for (int i = 0; i < k && !q.empty(); i++) {
            Node node = q.top();
            q.pop();
            res.push_back({node.x, node.y});
        }
        return res;
    }
};