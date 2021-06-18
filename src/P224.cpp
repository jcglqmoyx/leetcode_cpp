#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    stack<int> op;
    stack<int> nums;

    int calculate(string s) {
        if (s[0] == '+' || s[0] == '-') s = "0" + s;
        string tmp;
        for (char c : s) {
            if (c == ' ') continue;
            if (c == '-' && !tmp.empty() && tmp.back() == '+') {
                tmp.pop_back();
                tmp.push_back(c);
            } else {
                tmp.push_back(c);
            }
        }
        s = tmp;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                int x = 0, j = i;
                while (j < n && isdigit(s[j])) {
                    x = x * 10 + (s[j++] - '0');
                }
                nums.push(x);
                i = j - 1;
            } else if (s[i] == '(') {
                op.push(s[i]);
            } else if (s[i] == ')') {
                while (op.top() != '(') {
                    eval();
                }
                op.pop();
            } else if (is_operator(s[i]) && s[i - 1] != '(' && s[i - 1] != '+' && s[i - 1] != '-') {
                while (!op.empty() && op.top() != '(') {
                    eval();
                }
                op.push(s[i]);
            } else if (is_operator(s[i]) && (is_operator(s[i - 1]) || s[i - 1] == '(')) {
                int x = 0, j = i + 1;
                while (j < n && isdigit(s[j])) {
                    x = x * 10 + (s[j++] - '0');
                }
                i = j - 1;
                if (s[i - 1] == '-') {
                    x = -x;
                }
                nums.push(x);
            }
        }
        while (!op.empty()) eval();
        return nums.top();
    }

    bool is_operator(char c) {
        return c == '+' || c == '-';
    }

    void eval() {
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        int c = op.top();
        op.pop();
        switch (c) {
            case '+':
                nums.push(a + b);
                break;
            case '-':
                nums.push(a - b);
                break;
            default:
                break;
        }
    }
};