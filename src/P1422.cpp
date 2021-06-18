#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        vector<int> count_zero(s.length());
        vector<int> count_one(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                count_zero[i] = i > 0 ? count_zero[i - 1] + 1 : 1;
            } else {
                count_zero[i] = i > 0 ? count_zero[i - 1] : 0;
            }
        }
        for (int i = (int) s.length() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                count_one[i] = i < s.length() - 1 ? count_one[i + 1] + 1 : 1;
            } else {
                count_one[i] = i < s.length() - 1 ? count_one[i + 1] : 0;
            }
        }
        int max_score = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            max_score = max(max_score, count_zero[i] + count_one[i + 1]);
        }
        return max_score;
    }
};