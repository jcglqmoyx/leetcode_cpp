#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        for (int i = 0; i < A.size(); i++) {
            flip(A[i]);
            invert(A[i]);
        }
        return A;
    }

    void flip(vector<int> &nums) {
        for (int i = 0; i < nums.size() / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[nums.size() - i - 1];
            nums[nums.size() - i - 1] = temp;
        }
    }

    void invert(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] ^= 1;
        }
    }
};