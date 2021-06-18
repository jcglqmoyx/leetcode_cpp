#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int len = s.length() / 2; len >= 1; len--) {
            if (s.length() % len == 0) {
                bool flag = true;
                for (int i = 0; i < s.length() - len; i += len) {
                    if (s.substr(i, len) != s.substr(i + len, len)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};