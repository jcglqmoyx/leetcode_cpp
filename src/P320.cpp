#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n;
    vector<string> abbreviations;

    vector<string> generateAbbreviations(string word) {
        n = word.size();
        string cur;
        backtrack(word, cur, 0, 0);
        return abbreviations;
    }

    void backtrack(string &word, string &cur, int i, int count) {
        int len = cur.length();
        if (i == n) {
            if (count) {
                cur += to_string(count);
            }
            abbreviations.push_back(cur);
        } else {
            backtrack(word, cur, i + 1, count + 1);
            if (count) cur += to_string(count);
            cur.push_back(word[i]);
            backtrack(word, cur, i + 1, 0);
        }
        cur = cur.substr(0, len);
    }
};