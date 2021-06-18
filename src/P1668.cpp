#include <string>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if (sequence.length() < word.length()) return 0;
        int max_repeating = 0;
        for (int i = 0; i < sequence.length() - word.length() + 1; i++) {
            int repeating = 0;
            if (sequence.substr(i, word.length()) == word) {
                for (int j = i; j < sequence.length(); j += word.length()) {
                    if (sequence.substr(j, word.length()) == word) {
                        repeating++;
                        max_repeating = max(max_repeating, repeating);
                    } else {
                        break;
                    }
                }
            }
        }
        return max_repeating;
    }
};