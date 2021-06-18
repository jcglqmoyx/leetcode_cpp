#include <cmath>

class Solution {
public:
    bool isArmstrong(int N) {
        int n = N, m = N;
        int digits = 0;
        int sum = 0;
        while (N) {
            digits++;
            N /= 10;
        }
        while (n) {
            int digit = n % 10;
            sum += (int) pow(digit, digits);
            n /= 10;
        }
        return m == sum;
    }
};