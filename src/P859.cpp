#include <string>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        int count_diff = 0;
        int count[26] = {0};
        bool exist_even_count = false;
        char a, b;
        for (int i = 0; i < A.length(); i++) {
            if (A[i] != B[i]) {
                if (count_diff > 2) {
                    return false;
                }
                if (count_diff == 0) {
                    a = A[i];
                    b = B[i];
                } else if (A[i] != b || B[i] != a) {
                    return false;
                }
                count_diff++;
            }
            count[A[i] - 'a']++;
            if (count[A[i] - 'a'] == 2) {
                exist_even_count = true;
            }
        }
        if (count_diff == 0) {
            return exist_even_count;
        }
        return count_diff == 2;
    }
};