#include <vector>

using namespace std;

//class Solution {
//public:
//    int findMagicIndex(vector<int> &nums) {
//        return find(nums, 0, (int) nums.size() - 1);
//    }
//
//    int find(vector<int> &nums, int low, int high) {
//        if (low > high) return -1;
//        int mid = low + (high - low) / 2;
//        int left = find(nums, low, mid - 1);
//        if (left != -1) return left;
//        if (nums[mid] == mid) return mid;
//        return find(nums, mid + 1, high);
//    }
//};

class Solution {
public:
    int findMagicIndex(vector<int> &nums) {
        for (int i = 0; i < nums.size();) {
            if (i == nums[i]) return i;
            else if (i < nums[i]) i = nums[i];
            else i++;
        }
        return -1;
    }
};