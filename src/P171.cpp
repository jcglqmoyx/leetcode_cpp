#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        for (int i = 0; i < s.length(); i++) {
            number *= 26;
            number += s[i] - 'A' + 1;
        }
        return number;
    }
};