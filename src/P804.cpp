#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        unordered_set<string> translations;
        string morse_codes[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                                  "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                                  "-.--", "--.."};
        for (string word : words) {
            string morse_code;
            for (char c : word) {
                morse_code += morse_codes[c - 'a'];
            }
            translations.insert(morse_code);
        }
        return translations.size();
    }
};