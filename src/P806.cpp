#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int> &widths, string S) {
        int lines = 1;
        int wid = 100;
        for (int i = 0; i < S.size(); i++) {
            if (wid >= widths[S[i] - 'a']) {
                wid -= widths[S[i] - 'a'];
            } else {
                lines++;
                wid = 100 - widths[S[i] - 'a'];
            }
        }
        return {lines, 100 - wid};
    }
};