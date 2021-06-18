#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stk;
        int add = 0;
        for (char c : S) {
            if (c == '(') {
                stk.push(c);
            } else {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    add++;
                }
            }
        }
        add += stk.size();
        return add;
    }
};