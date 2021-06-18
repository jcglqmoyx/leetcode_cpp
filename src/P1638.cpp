#include <string>

using namespace std;

class Solution {
public:
    string a, b;

    bool diff_by_one(int i, int j, int p) {
        int cnt = 0;
        for (int index = i; index <= j; index++) {
            if (a[index] != b[p + index - i]) {
                cnt++;
            }
        }
        return cnt == 1;
    }

    int countSubstrings(string s, string t) {
        a = s, b = t;
        int cnt = 0;
        int n = s.length(), m = t.length();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                for (int k = 0; k + len <= m; k++) {
                    if (diff_by_one(i, j, k)) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};