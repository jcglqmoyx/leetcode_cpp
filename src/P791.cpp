#include <string>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        int count[123] = {0};
        for (char c : T) count[c]++;
        string res;
        for (char c : S) {
            if (count[c]) {
                for (int i = 0; i < count[c]; i++) {
                    res.push_back(c);
                }
                count[c] = 0;
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (count[c]) {
                for (int i = 0; i < count[c]; i++) {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};