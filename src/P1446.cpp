#include <string>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int power = 1, max_power = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                power++;
                max_power = max(max_power, power);
            } else {
                power = 1;
            }
        }
        return max_power;
    }
};