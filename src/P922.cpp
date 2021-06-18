#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &A) {
        int even = 0, odd = 1;
        while (even < A.size() && odd < A.size()) {
            while (even < A.size() && A[even] % 2 == 0) {
                even += 2;
            }
            while (odd < A.size() && A[odd] % 2 == 1) {
                odd += 2;
            }
            if (odd < A.size() && even < A.size()) {
                swap(A[odd], A[even]);
            }
            odd += 2;
            even += 2;
        }
        return A;
    }
};