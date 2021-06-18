#include <string>

using namespace std;

class Solution {
public:
    string maskPII(string S) {
        int n = S.length();
        bool is_email = false;
        for (char c : S) {
            if (c == '@') {
                is_email = true;
                break;
            }
        }
        string res;
        if (is_email) {
            res.push_back(tolower(S.front()));
            res += "*****";
            for (int i = 0; i < n; i++) {
                if (S[i] != '@') continue;
                res.push_back(tolower(S[i - 1]));
                for (int j = i; j < n; j++) {
                    if (isalpha(S[j])) res.push_back(tolower(S[j]));
                    else res.push_back(S[j]);
                }
                break;
            }
        } else {
            int cnt = 0;
            string s;
            for (int i = 0; i < n; i++) {
                if (isdigit(S[i])) cnt++, s.push_back(S[i]);
            }
            if (cnt == 10) return "***-***-" + s.substr(6, 4);
            res = "+";
            for (int i = 0; i < s.length() - 10; i++) res.push_back('*');
            res += "-***-***-";
            res += s.substr(s.length() - 4, 4);
        }
        return res;
    }
};