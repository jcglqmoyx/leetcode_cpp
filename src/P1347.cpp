#include <string>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int count1[26] = {0}, count2[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count1[s[i] - 'a']++;
            count2[t[i] - 'a']++;
        }
        int step = 0;
        for (int i = 0; i < 26; i++) {
            if (count1[i] > count2[i]) {
                step += count1[i] - count2[i];
            }
        }
        return step;
    }
};