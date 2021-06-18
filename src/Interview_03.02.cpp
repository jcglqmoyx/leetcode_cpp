#include <stack>
#include <cstdint>

using namespace std;

class MinStack {
public:
    stack<int> stk, min_stk;

    MinStack() {
        min_stk.push(INT32_MAX);
    }

    void push(int x) {
        stk.push(x);
        min_stk.push(min(x, min_stk.top()));
    }

    void pop() {
        stk.pop();
        min_stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
};