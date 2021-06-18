#include <string>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        string res;
        int space = 0;
        int start = 0, i = 0;
        while (i <= S.length()) {
            if (i == S.length() || S[i] == ' ') {
                space++;
                if (is_vowel(S[start])) {
                    res += S.substr(start, i - start) + "ma";
                } else {
                    res += S.substr(start + 1, i - start - 1) + S[start] + "ma";
                }
                start = i + 1;
                for (int count = 0; count < space; count++) {
                    res += 'a';
                }
                res += ' ';
            }
            i++;
        }
        res.pop_back();
        return res;
    }

    static bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A'
               || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};