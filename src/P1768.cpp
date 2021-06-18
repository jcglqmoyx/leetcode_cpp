#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int i = 0, j = 0;
        string res;
        while (i < len1 || j < len2) {
            if (i < len1 && j < len2) {
                res.push_back(word1[i++]);
                res.push_back(word2[j++]);
            } else if (i < len1) {
                res.push_back(word1[i++]);
            } else {
                res.push_back(word2[j++]);
            }
        }
        return res;
    }
};