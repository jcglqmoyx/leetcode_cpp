#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<char, int>> map;
    int n;

    bool valid(string &s, string &w) {
        int m = w.length();
        if (m > n) return false;
        vector<pair<char, int>> groups;
        int len = 1;
        for (int i = 0; i < m - 1; i++) {
            if (w[i] == w[i + 1]) {
                len++;
                if (i == m - 2) groups.emplace_back(w[i], len);
            } else {
                groups.emplace_back(w[i], len);
                if (i == m - 2) groups.emplace_back(w[m - 1], 1);
                len = 1;
            }
        }
        int len1 = map.size(), len2 = groups.size();
        if (len1 != len2) return false;
        for (int i = 0; i < len1; i++) {
            if (map[i].first != groups[i].first) return false;
            if (map[i].second < groups[i].second || map[i].second > groups[i].second && map[i].second < 3) return false;
        }
        return true;
    }

    int expressiveWords(string S, vector<string> &words) {
        n = S.length();
        int len = 1;
        for (int i = 0; i < n - 1; i++) {
            if (S[i] == S[i + 1]) {
                len++;
                if (i == n - 2) map.emplace_back(S[i], len);
            } else {
                map.emplace_back(S[i], len);
                if (i == n - 2) map.emplace_back(S[n - 1], 1);
                len = 1;
            }
        }
        int cnt = 0;
        for (string &w : words) {
            if (valid(S, w)) cnt++;
        }
        return cnt;
    }
};