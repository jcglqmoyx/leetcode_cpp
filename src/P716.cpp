#include <stack>

using namespace std;

class MaxStack {
public:
    stack<int> stk;
    stack<int> max_stk;

    MaxStack() {
    }

    void push(int x) {
        stk.push(x);
        if (max_stk.empty()) max_stk.push(x);
        else max_stk.push(max(max_stk.top(), x));
    }

    int pop() {
        int top = stk.top();
        stk.pop();
        max_stk.pop();
        return top;
    }

    int top() {
        return stk.top();
    }

    int peekMax() {
        return max_stk.top();
    }

    int popMax() {
        stack<int> buffer;
        int max_value = max_stk.top();
        while (stk.top() != max_value) {
            buffer.push(top());
            pop();
        }
        pop();
        while (!buffer.empty()) {
            push(buffer.top());
            buffer.pop();
        }
        return max_value;
    }
};