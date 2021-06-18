#include <string>

using namespace std;

class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int res = 0, len = 0;
        for (int i = 0; i < k; i++) {
            if (is_vowel(s[i])) len++, res++;
        }
        for (int i = k; i < n; i++) {
            if (is_vowel(s[i])) len++;
            if (is_vowel(s[i - k])) len--;
            res = max(res, len);
        }
        return res;
    }
};