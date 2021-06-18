#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.length();
        unordered_set<char> set;
        for (int i = 0, j = 0; j < n; j++) {
            while (set.count(s[j])) {
                set.erase(s[i++]);
            }
            set.insert(s[j]);
            res = max(res, j - i + 1);
        }
        return res;
    }
};