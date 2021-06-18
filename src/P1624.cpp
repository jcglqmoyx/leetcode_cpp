#include <string>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int map[26];
        for (int i = 0; i < 26; i++) {
            map[i] = -1;
        }
        int max_len = -1;
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i] - 'a'] >= 0) {
                max_len = max(max_len, i - map[s[i] - 'a'] - 1);
            } else {
                map[s[i] - 'a'] = i;
            }
        }
        return max_len;
    }
};