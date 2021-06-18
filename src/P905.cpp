#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int low = 0, high = (int) A.size() - 1;
        while (low < high) {
            while (low < high && A[low] % 2 == 0) {
                low++;
            }
            while (low < high && A[high] % 2 == 1) {
                high--;
            }
            int temp = A[low];
            A[low] = A[high];
            A[high] = temp;
        }
        return A;
    }
};