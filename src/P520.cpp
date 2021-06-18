#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (char c : word) {
            if (isupper(c)) {
                count++;
            }
        }
        if (count == 0 || count == (int) word.length()) {
            return true;
        } else if (count == 1 && isupper(word[0])) {
            return true;
        }
        return false;
    }
};