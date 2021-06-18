#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<int> shuffle(vector<int> &nums, int n) {
//        vector<int> res(2 * n);
//        int left = 0, right = n;
//        for (int i = 0; i < 2 * n; i += 2) {
//            res[i] = nums[left];
//            res[i + 1] = nums[right];
//            left++;
//            right++;
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<int> shuffle(vector<int> &nums, int n) {
        for (int i = n; i < 2 * n; i++) {
            nums[i] |= (nums[i - n] << 10);
        }
        for (int i = 0; i < n; i++) {
            int j = i * 2;
            nums[j] = nums[i + n] >> 10;
            nums[j + 1] = nums[i + n] & 1023;
        }
        return nums;
    }
};