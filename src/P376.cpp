#include <vector>

using namespace std;

//class Solution {
//public:
//    int wiggleMaxLength(vector<int> &nums) {
//        int n = nums.size();
//        vector<int> increase(n, 1);
//        vector<int> decrease(n, 1);
//        for (int i = 0; i < n; i++) {
//            for (int j = i - 1; j >= 0; j--) {
//                if (nums[j] < nums[i]) {
//                    increase[i] = max(increase[i], decrease[j] + 1);
//                } else if (nums[j] > nums[i]) {
//                    decrease[i] = max(decrease[i], increase[j] + 1);
//                }
//            }
//        }
//        return max(increase.back(), decrease.back());
//    }
//};

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return 1;
        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};