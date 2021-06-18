#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int map[128] = {0};
        map['M'] = 1000;
        map['D'] = 500;
        map['C'] = 100;
        map['L'] = 50;
        map['X'] = 10;
        map['V'] = 5;
        map['I'] = 1;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && map[s[i]] < map[s[i + 1]]) {
                res -= map[s[i]];
            } else {
                res += map[s[i]];
            }
        }
        return res;
    }
};