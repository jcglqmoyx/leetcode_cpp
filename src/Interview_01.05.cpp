#include <string>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first.length() > second.size()) return oneEditAway(second, first);
        int m = first.length(), n = second.length();
        if (n - m > 1) return false;
        if (m == n) {
            for (int i = 0, j = 0; i < m; i++, j++) {
                if (first[i] != second[j]) {
                    return first.substr(i + 1) == second.substr(j + 1);
                }
            }
            return true;
        }
        for (int i = 0, j = 0; i < m; i++, j++) {
            if (first[i] != second[j]) {
                return first.substr(i) == second.substr(j + 1);
            }
        }
        return true;
    }
};