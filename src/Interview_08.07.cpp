#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> res;

    vector<string> permutation(string S) {
        dfs(S, 0);
        return res;
    }

    void dfs(string &s, int index) {
        if (index == s.length()) {
            res.push_back(s);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            swap(s[i], s[index]);
            dfs(s, index + 1);
            swap(s[i], s[index]);
        }
    }
};