#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> min_q;
    priority_queue<int> max_q;

    MedianFinder() {
    }

    void addNum(int num) {
        if (min_q.size() == max_q.size()) {
            min_q.push(num);
            max_q.push(min_q.top());
            min_q.pop();
        } else {
            max_q.push(num);
            min_q.push(max_q.top());
            max_q.pop();
        }
    }

    double findMedian() {
        return min_q.size() == max_q.size() ? (min_q.top() + max_q.top()) / 2.0 : max_q.top();
    }
};