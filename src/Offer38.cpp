#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> res;
    string str;
    vector<bool> used;

    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        used.resize(s.length());
        backtrack(s, 0);
        return res;
    }

    void backtrack(string &s, int index) {
        if (index == s.length()) {
            res.push_back(str);
            return;
        }
        for (int i = 0; i < s.length(); i++) {
            if (used[i] || i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;
            str.push_back(s[i]);
            used[i] = true;
            backtrack(s, index + 1);
            str.pop_back();
            used[i] = false;
        }
    }
};