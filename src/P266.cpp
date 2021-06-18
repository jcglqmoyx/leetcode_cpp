#include <string>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int map[128] = {0};
        for (char c : s) map[c]++;
        int count_odd = 0;
        for (int freq : map) if (freq % 2 == 1) count_odd++;
        return count_odd <= 1;
    }
};