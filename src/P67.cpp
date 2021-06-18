#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = (int) a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            if (i >= 0 && j >= 0) {
                int x = a[i] - 48;
                int y = b[j] - 48;
                int sum = x + y + carry;
                res += to_string(sum % 2);
                carry = sum / 2;
                i--;
                j--;
            } else if (i >= 0) {
                int x = a[i] - 48;
                int sum = x + carry;
                res += to_string(sum % 2);
                carry = sum / 2;
                i--;
            } else {
                int y = b[j] - 48;
                int sum = y + carry;
                res += to_string(sum % 2);
                carry = sum / 2;
                i--;
                j--;
            }
        }
        if (carry) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};