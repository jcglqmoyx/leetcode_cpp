#include <vector>

using namespace std;

class CustomStack {
public:
    vector<int> stk, add;
    int capacity;

    CustomStack(int maxSize) {
        capacity = maxSize;
        stk.reserve(capacity);
        add.resize(capacity);
    }

    void push(int x) {
        if (stk.size() < capacity) {
            stk.push_back(x);
        }
    }

    int pop() {
        if (stk.empty()) return -1;
        if (add[(int) stk.size() - 1] != 0) {
            for (int i = 0; i < stk.size(); i++) {
                stk[i] += add[(int) stk.size() - 1];
            }
        }
        add[stk.size() - 1] = 0;
        int val = stk.back();
        stk.pop_back();
        return val;
    }

    void increment(int k, int val) {
        if (stk.empty()) return;
        add[min(k - 1, (int) stk.size() - 1)] += val;
    }
};