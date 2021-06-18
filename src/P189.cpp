#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int count = 0;
        k %= nums.size();
        flip(nums, 0, (int) nums.size() - 1);
        flip(nums, 0, k - 1);
        flip(nums, k, (int) nums.size() - 1);
    }

    void flip(vector<int> &nums, int low, int high) {
        while (low < high) {
            swap(nums[low++], nums[high--]);
        }
    }
};

class Solution1 {
public:
    void rotate(vector<int> &nums, int k) {
        for (int start = 0, count = 0; count < nums.size(); start++) {
            int cur = start;
            int prev = nums[cur];
            do {
                int next = (cur + k) % (int) nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                cur = next;
                count++;
            } while (start != cur);
        }
    }
};