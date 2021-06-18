#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        if (n == 2) {
            return "11";
        }
        string last = countAndSay(n - 1), res;
        int count = 1;
        int len = (int) last.length();
        for (int i = 1; i < len; i++) {
            if (last[i] == last[i - 1]) {
                count++;
            } else if (last[i] != last[i - 1]) {
                res += to_string(count) + last[i - 1];
                count = 1;
            }
            if (i == len - 1) {
                if (last[i] == last[i - 1]) {
                    res += to_string(count) + last[i];
                } else {
                    res += to_string(1) + last[i];
                }
            }
        }
        return res;
    }
};