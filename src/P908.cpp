#include <vector>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int> &A, int K) {
        int minimum = 10000, maximum = 0;
        for (int num : A) {
            minimum = min(minimum, num);
            maximum = max(maximum, num);
        }
        return max(maximum - minimum - 2 * K, 0);
    }
};