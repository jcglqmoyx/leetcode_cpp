#include <vector>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int> &A) {
        int sum = 0;
        for (int num : A) {
            sum += num;
        }
        if (sum % 3) {
            return false;
        }
        int low = 0, high = (int) A.size() - 1;
        int left_sum = 0, right_sum = 0;
        while (low < high) {
            left_sum += A[low++];
            if (left_sum == sum / 3) {
                break;
            }
        }
        if (low == high) {
            return false;
        }
        bool flag = false;
        while (high > low) {
            right_sum += A[high--];
            if (right_sum == sum / 3) {
                flag = true;
                break;
            }
        }
        return flag;
    }
};