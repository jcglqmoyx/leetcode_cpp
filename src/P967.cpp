#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> res;

    vector<int> numsSameConsecDiff(int n, int k) {
        string s;
        dfs(s, n, k);
        return res;
    }

    void dfs(string &s, int n, int k) {
        if (s.length() == n) {
            res.push_back(stoi(s));
            return;
        }
        for (int i = 0; i <= 9; i++) {
            if (i == 0 && s.empty()) continue;
            if (i + k > 9 && i - k < 0) continue;
            if (!s.empty()) {
                int last = s.back() - '0';
                if (abs(last - i) != k) continue;
            }
            s.push_back((char) (i + '0'));
            dfs(s, n, k);
            s.pop_back();
        }
    }
};