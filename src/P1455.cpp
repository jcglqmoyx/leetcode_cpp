#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        int low = 0;
        for (int i = 0; i < sentence.length(); i++) {
            if (i == sentence.length() - 1) {
                words.push_back(sentence.substr(low, i - low + 1));
            } else if (sentence[i] == ' ') {
                words.push_back(sentence.substr(low, i - low));
                low = i + 1;
            }
        }
        for (int i = 0; i < words.size(); i++) {
            if (words[i].substr(0, searchWord.length()) == searchWord) {
                return i + 1;
            }
        }
        return -1;
    }
};