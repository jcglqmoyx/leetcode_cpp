#include <cmath>

class Solution {
public:
    int arrangeCoins(int n) {
        return sqrt((long) n * 2 + 0.25) - 0.5;
    }
};