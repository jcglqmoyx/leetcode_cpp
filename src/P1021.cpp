#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int left = 0;
        for (char c : S) {
            if (c == ')') {
                left--;
            }
            if (left) {
                res += c;
            }
            if (c == '(') {
                left++;
            }
        }
        return res;
    }
};