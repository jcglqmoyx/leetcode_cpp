#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (is_operator(tokens[i])) {
                int y = stk.top();
                stk.pop();
                int x = stk.top();
                stk.pop();
                stk.push(calculate(x, y, tokens[i]));
            } else stk.push(stoi(tokens[i]));
        }
        return stk.top();
    }

    int calculate(int x, int y, string &operation) {
        if (operation == "+") return x + y;
        else if (operation == "-") return x - y;
        else if (operation == "*") return x * y;
        else return x / y;
    }

    bool is_operator(string &token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};