#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i + 1] == s[i]) {
                count++;
                if (s[i + 1] == '1') {
                    s[i + 1] = '0';
                } else {
                    s[i + 1] = '1';
                }
            }
        }
        return min(count, (int) s.length() - count);
    }
};