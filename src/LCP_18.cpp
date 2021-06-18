#include <vector>

using namespace std;

class Solution {
public:
    int breakfastNumber(vector<int> &staple, vector<int> &drinks, int x) {
        int count = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        if (staple.size() > drinks.size()) swap(staple, drinks);
        for (int i = 0; i < staple.size(); i++) {
            if (staple[i] >= x) break;
            int idx = binary_search(drinks, 0, (int) drinks.size(), x - staple[i]);
            count = (count + idx) % 1000000007;
        }
        return count;
    }

    int binary_search(vector<int> &arr, int low, int high, int target) {
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};