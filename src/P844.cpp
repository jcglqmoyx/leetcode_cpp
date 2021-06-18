#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s, t;
        for (char c : S) {
            if (c != '#') {
                s.push_back(c);
            } else if (!s.empty()) {
                s.pop_back();
            }
        }
        for (char c : T) {
            if (c != '#') {
                t.push_back(c);
            } else if (!t.empty()) {
                t.pop_back();
            }
        }
        return s == t;
    }
};