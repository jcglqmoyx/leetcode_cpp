#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() > str2.length()) {
            return gcdOfStrings(str2, str1);
        }
        for (int len = (int) str1.length(); len >= 1; len--) {
            string divisor = str1.substr(0, len);
            if (str1.length() % len != 0 || str2.length() % len != 0) {
                continue;
            }
            if (is_common_divisor(str1, divisor) && is_common_divisor(str2, divisor)) {
                return divisor;
            }
        }
        return "";
    }

    bool is_common_divisor(const string &str, const string &divisor) {
        for (int i = 0; i < str.length(); i += (int) divisor.length()) {
            if (str.substr(i, divisor.length()) != divisor) {
                return false;
            }
        }
        return true;
    }
};