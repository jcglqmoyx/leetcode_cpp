#include <string>

using namespace std;

class Solution {
public:
    int countLetters(string S) {
        int len = 1;
        int res = 0;
        int n = S.length();
        S.push_back('A');
        for (int i = 0; i < n; i++) {
            if (S[i] == S[i + 1]) {
                len++;
            } else {
                res += len * (len + 1) / 2;
                len = 1;
            }
        }
        return res;
    }
};