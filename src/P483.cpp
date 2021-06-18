#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long n_val = stol(n);
        int m_max = floor(log(n_val) / log(2));
        for (int m = 2; m <= m_max; m++) {
            int k = pow(n_val, 1.0 / m);
            long mul = 1, sum = 1;
            for (int i = 0; i < m; i++) {
                mul *= k;
                sum += mul;
            }
            if (sum == n_val) {
                return to_string(k);
            }
        }
        return to_string(n_val - 1);
    }
};