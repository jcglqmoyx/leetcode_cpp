#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    size_t n;
    unordered_set<string> set;
    int res;

    int maxUniqueSplit(string s) {
        n = s.length();
        res = 0;
        dfs(s, 0);
        return res;
    }

    void dfs(string &s, int idx) {
        if (idx == n) {
            res = max(res, (int) set.size());
            return;
        }
        for (int len = 1; idx + len <= n; len++) {
            string sub = s.substr(idx, len);
            if (set.count(sub)) continue;
            set.insert(sub);
            dfs(s, idx + len);
            set.erase(sub);
        }
    }
};