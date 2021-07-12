#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int initial_len;
    int min_len, max_len;
    int res = 1;
    unordered_map<string, int> m;

    void dfs(string &w) {
        res = max(res, (int) w.size() - initial_len + 1);
        if (res == max_len - min_len + 1) return;
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i <= w.length(); i++) {
                string t = w.substr(0, i) + c;
                if (i < w.length()) t += w.substr(i);
                if (m.count(t)) {
                    m[t]--;
                    if (m[t] == 0) m.erase(t);
                    dfs(t);
                    m[t]++;
                }
            }
        }
    }

    int longestStrChain(vector<string> &words) {
        for (auto &w : words) m[w]++;
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });
        min_len = (int) words[0].size(), max_len = (int) words.back().size();
        for (string &w : words) {
            initial_len = (int) w.size();
            dfs(w);
        }
        return res;
    }
};