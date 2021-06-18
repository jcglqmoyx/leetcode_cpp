#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        vector<int> res;
        res.reserve(k);
        priority_queue<int> q;
        for (int num : arr) {
            q.push(num);
            if (q.size() > k) q.pop();
        }
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};