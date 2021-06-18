#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int min_diff = 1e9;
    vector<int> closest_divisors;

    vector<int> closestDivisors(int num) {
        calc(num + 1);
        calc(num + 2);
        return closest_divisors;
    }

    void calc(int num) {
        for (int i = sqrt(num); i >= 1; i--) {
            if (num % i == 0) {
                int diff = num / i - i;
                if (diff < min_diff) {
                    min_diff = diff;
                    closest_divisors = {i, num / i};
                }
                break;
            }
        }
    }
};