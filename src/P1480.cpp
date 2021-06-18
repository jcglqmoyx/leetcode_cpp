#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<int> runningSum(vector<int> &nums) {
//        vector<int> res(nums.size());
//        int prev = 0;
//        for (int i = 0; i < res.size(); i++) {
//            res[i] = prev + nums[i];
//            prev = res[i];
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};