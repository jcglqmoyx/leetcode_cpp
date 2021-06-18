#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n2 < n1) return false;
        int map1[26] = {0}, map2[26] = {0};
        for (char c : s1) map1[c - 'a']++;
        for (int i = 0; i < n1; i++) {
            map2[s2[i] - 'a']++;
        }
        if (equal(map1, map2)) return true;
        for (int i = 1; i <= n2 - n1; i++) {
            map2[s2[i - 1] - 'a']--;
            map2[s2[i + n1 - 1] - 'a']++;
            if (equal(map1, map2)) return true;
        }
        return false;
    }

    bool equal(const int *map1, const int *map2) {
        for (int i = 0; i < 26; i++) {
            if (map1[i] != map2[i]) {
                return false;
            }
        }
        return true;
    }
};