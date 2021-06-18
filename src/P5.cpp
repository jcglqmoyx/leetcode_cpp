#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest_palindrome = s.substr(0, 1);
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && s[i] == s[i + 1]) {
                int low = i, high = i + 1;
                while (low >= 0 && high < s.length() && s[low] == s[high]) {
                    low--;
                    high++;
                }
                if (high - low - 1 > longest_palindrome.length()) {
                    longest_palindrome = s.substr(low + 1, high - low - 1);
                }
            }
            if (i > 0 && i < s.length() - 1 && s[i - 1] == s[i + 1]) {
                int low = i - 1, high = i + 1;
                while (low >= 0 && high < s.length() && s[low] == s[high]) {
                    low--;
                    high++;
                }
                if (high - low - 1 > longest_palindrome.length()) {
                    longest_palindrome = s.substr(low + 1, high - low - 1);
                }
            }
        }
        return longest_palindrome;
    }
};