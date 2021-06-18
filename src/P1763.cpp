#include <string>

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        string res;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j <= n; j++) {
                string str = s.substr(i, j - i + 1);
                if (is_nice(str) && str.length() > res.length()) {
                    res = str;
                }
            }
        }
        return res;
    }

    bool is_nice(string &str) {
        int count1[26] = {0};
        int count2[26] = {0};
        for (char c : str) {
            if (isupper(c)) count1[c - 'A']++;
            else count2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (!count1[i] && count2[i] || count1[i] && !count2[i]) {
                return false;
            }
        }
        return true;
    }
};