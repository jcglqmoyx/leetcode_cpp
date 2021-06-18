#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ms[128] = {0};
        int mt[128] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (ms[s[i]] && ms[s[i]] != t[i] || mt[t[i]] && mt[t[i]] != s[i]) {
                return false;
            }
            ms[s[i]] = t[i];
            mt[t[i]] = s[i];
        }
        return true;
    }
};