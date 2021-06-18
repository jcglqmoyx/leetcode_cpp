#include <string>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num), t = s;
        sort(t.begin(), t.end(), [](char a, char b) {
            return a > b;
        });
        if (s == t) return num;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char mx = s[i];
            for (int j = i + 1; j < n; j++) {
                if (s[j] > mx) {
                    mx = s[j];
                }
            }
            if (mx == s[i]) continue;
            for (int j = n - 1; j > i; j--) {
                if (s[j] == mx) {
                    swap(s[i], s[j]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};