#include <string>

using namespace std;

class Solution {
public:
    int helper(string &s) {
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        int mx = 0, mn = INT32_MAX;
        for (int i = 0; i < 26; i++) {
            if (count[i]) {
                mx = max(mx, count[i]);
                mn = min(mn, count[i]);
            }
        }
        return mx - mn;
    }

    int beautySum(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                string str = s.substr(i, j - i + 1);
                sum += helper(str);
            }
        }
        return sum;
    }
};