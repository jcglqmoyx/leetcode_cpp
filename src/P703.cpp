#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> q;

    int k;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (int num : nums) {
            q.push(num);
            if (q.size() > this->k) {
                q.pop();
            }
        }
    }

    int add(int val) {
        this->q.push(val);
        if (this->q.size() > this->k) {
            this->q.pop();
        }
        return this->q.top();
    }
};