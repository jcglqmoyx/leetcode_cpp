#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int> &arr) {
        if (arr.size() < 3) return 0;
        int n = arr.size();
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int left = i - 1, right = i + 1;
                while (left > 0 && arr[left] > arr[left - 1]) left--;
                while (right < n - 1 && arr[right] > arr[right + 1]) right++;
                res = max(res, right - left + 1);
                i = right;
            }
        }
        return res;
    }
};