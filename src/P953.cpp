#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        int map[26] = {0};
        for (int i = 0; i < 26; i++) {
            map[order[i] - 'a'] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                if (j == (int) words[i + 1].length() || map[words[i][j] - 'a'] > map[words[i + 1][j] - 'a']) {
                    return false;
                }
                if (map[words[i][j] - 'a'] < map[words[i + 1][j] - 'a']) {
                    break;
                }
            }
        }
        return true;
    }
};