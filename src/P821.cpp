#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.length());
        int low = 0, high = 0;
        while (S[low] != C) {
            low++;
        }
        high = low;
        for (int i = 0; i < S.length(); i++) {
            if (i >= high) {
                low = high;
                int j = high + 1;
                while (j < S.length() && S[j] != C) {
                    j++;
                }
                if (j < S.length()) {
                    high = j;
                }
            }
            res[i] = min(abs(low - i), abs(high - i));
        }
        return res;
    }
};