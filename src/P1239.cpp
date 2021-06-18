#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int res = 0;

    int maxLength(vector<string> &arr) {
        string cur;
        dfs(arr, cur, 0);
        return res;
    }

    bool is_valid(string &s) {
        if (s.size() > 26) return false;
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
            if (cnt[c - 'a'] > 1) {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<string> &arr, string &cur, int index) {
        if (index == arr.size()) {
            res = max(res, (int) cur.size());
            return;
        }
        int len = cur.size();
        cur += arr[index];
        if (is_valid(cur)) {
            dfs(arr, cur, index + 1);
        }
        cur = cur.substr(0, len);
        dfs(arr, cur, index + 1);
    }
};