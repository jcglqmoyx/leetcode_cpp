#include <string>

using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        long count = 0;
        long len = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                len++;
                if (i == s.length() - 1) {
                    count += len * (len + 1) / 2;
                }
            } else {
                count += len * (len + 1) / 2;
                len = 1;
            }
            count %= 1000000007;
        }
        if (len == 1) count++;
        return (int) count;
    }
};