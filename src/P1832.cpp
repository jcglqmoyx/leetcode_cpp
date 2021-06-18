#include <string>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt[26] = {0};
        for (char c : sentence) cnt[c - 'a']++;
        for (int i : cnt) if (i == 0) return false;
        return true;
    }
};