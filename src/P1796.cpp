#include <string>

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                if (num > second) {
                    if (num > first) {
                        second = first;
                        first = num;
                    } else if (num < first) {
                        second = num;
                    }
                }
            }
        }
        return second;
    }
};