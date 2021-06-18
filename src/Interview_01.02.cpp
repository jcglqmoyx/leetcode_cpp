#include <string>

using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int map[128] = {0};
        for (int i = 0; i < s1.length(); i++) {
            map[s1[i]]++;
            map[s2[i]]--;
        }
        for (int i = 0; i < 128; i++) if (map[i]) return false;
        return true;
    }
};