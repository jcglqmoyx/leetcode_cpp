#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int temp = q.front();
        q.front() = q.back();
        q.back() = temp;
        int value = q.front();
        q.pop();

        if (!q.empty()) {
            temp = q.front();
            q.front() = q.back();
            q.back() = temp;
        }
        return value;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};