#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        vector<int> res(A.size());
        int index = (int) A.size() - 1;
        int carry = 0;
        while (index >= 0 || K) {
            if (index >= 0 && K) {
                int sum = A[index] + K % 10 + carry;
                A[index--] = sum % 10;
                carry = sum / 10;
                K /= 10;
            } else if (index >= 0) {
                int sum = A[index] + carry;
                A[index--] = sum % 10;
                carry = sum / 10;
            } else {
                int sum = K % 10 + carry;
                carry = sum / 10;
                A.insert(A.begin(), sum % 10);
                K /= 10;
            }
        }
        if (carry) {
            A.insert(A.begin(), 1);
        }
        return A;
    }
};