#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left_odd = (i + 1) / 2;
            int left_even = i / 2 + 1;
            int right_odd = ((int) arr.size() - i) / 2;
            int right_even = ((int) arr.size() - i + 1) / 2;
            sum += (left_odd * right_odd + left_even * right_even) * arr[i];
        }
        return sum;
    }
};