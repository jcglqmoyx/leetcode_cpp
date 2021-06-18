#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> permutations;
    string cur;
    vector<bool> visited;

    vector<string> permutation(string S) {
        visited.resize(S.length());
        sort(S.begin(), S.end());
        dfs(S, 0);
        return permutations;
    }

    void dfs(string &s, int index) {
        if (index == s.length()) {
            permutations.push_back(cur);
            return;
        }
        for (int i = 0; i < s.length(); i++) {
            if (visited[i] || i > 0 && s[i] == s[i - 1] && !visited[i - 1]) continue;
            visited[i] = true;
            cur.push_back(s[i]);
            dfs(s, index + 1);
            cur.pop_back();
            visited[i] = false;
        }
    }
};