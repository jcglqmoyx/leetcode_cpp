#include <string>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (i == 0 || i > 0 && s[i - 1] != c) {
                        if (i == s.length() - 1 || i < s.length() - 1 && s[i + 1] != c) {
                            s[i] = c;
                            break;
                        }
                    }
                }
            }
        }
        return s;
    }
};