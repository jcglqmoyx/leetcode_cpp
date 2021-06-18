#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int> &A) {
        bool increasing = false, decreasing = false;
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] > A[i + 1]) {
                if (increasing) {
                    return false;
                }
                decreasing = true;
            } else if (A[i] < A[i + 1]) {
                if (decreasing) {
                    return false;
                }
                increasing = true;
            }
        }
        return true;
    }
};