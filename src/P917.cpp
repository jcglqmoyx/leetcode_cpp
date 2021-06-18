#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int low = 0, high = S.length() - 1;
        while (low < high) {
            while (low < high && !isalpha(S[low])) {
                low++;
            }
            while (low < high && !isalpha(S[high])) {
                high--;
            }
            char temp = S[low];
            S[low] = S[high];
            S[high] = temp;
            low++;
            high--;
        }
        return S;
    }
};