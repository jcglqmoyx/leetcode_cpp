#include <string>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.length() <= 1) {
            return s.length();
        }
        return is_palindrome(s) ? 1 : 2;
    }

    bool is_palindrome(const string &s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};