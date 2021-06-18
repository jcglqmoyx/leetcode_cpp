#include <stack>

using namespace std;

//class MyQueue {
//public:
//    stack<int> stack1, stack2;
//
//    MyQueue() {
//
//    }
//
//    void push(int x) {
//        stack1.push(x);
//    }
//
//    int pop() {
//        while (!stack1.empty()) {
//            stack2.push(stack1.top());
//            stack1.pop();
//        }
//        int val = stack2.top();
//        stack2.pop();
//        while (!stack2.empty()) {
//            stack1.push(stack2.top());
//            stack2.pop();
//        }
//        return val;
//    }
//
//    int peek() {
//        while (!stack1.empty()) {
//            stack2.push(stack1.top());
//            stack1.pop();
//        }
//        int val = stack2.top();
//        while (!stack2.empty()) {
//            stack1.push(stack2.top());
//            stack2.pop();
//        }
//        return val;
//    }
//
//    bool empty() {
//        return stack1.empty();
//    }
//};

class MyQueue {
public:
    MyQueue() {
    }

    void push(int x) {
        if (stack1.empty()) {
            front = x;
        }
        stack1.push(x);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int top = stack2.top();
        stack2.pop();
        return top;
    }

    int peek() {
        if (!stack2.empty()) return stack2.top();
        return front;
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }

private:
    stack<int> stack1, stack2;
    int front;
};