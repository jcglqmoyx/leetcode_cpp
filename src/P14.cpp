#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int max_len = 0;
        string s;
        for (const string &str : strs) {
            if (str.length() > max_len) {
                max_len = str.length();
                s = str;
            }
        }
        string longest_common_prefix;
        for (int len = 1; len <= s.length(); len++) {
            string prefix = s.substr(0, len);
            bool flag = true;
            for (const string& str : strs) {
                if (str.substr(0, len) != prefix) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                longest_common_prefix = prefix;
            }
        }
        return longest_common_prefix;
    }
};