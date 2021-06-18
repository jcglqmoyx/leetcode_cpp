#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        sort(nums);
        return nums;
    }

    void sort(vector<int> &nums) {
        quicksort(nums, 0, nums.size() - 1);
    }

    void quicksort(vector<int> &nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int j = partition(nums, low, high);
        quicksort(nums, low, j - 1);
        quicksort(nums, j + 1, high);
    }

    int partition(vector<int> &nums, int low, int high) {
        int pivot = nums[low];
        int i = low, j = high + 1;
        while (true) {
            while (nums[++i] <= pivot) {
                if (i == high) {
                    break;
                }
            }
            while (pivot < nums[--j]) {
                if (j == low) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }
};