#include <string>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int max_digit = 1;
        for (int i = 0; i < n.length(); i++) {
            max_digit = max(max_digit, n[i] - 48);
        }
        return max_digit;
    }
};