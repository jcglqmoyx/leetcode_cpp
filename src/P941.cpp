#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int> &arr) {
        if (arr.size() < 3) {
            return false;
        }
        int len = (int) arr.size();
        int i = 0;
        while (i < arr.size() - 1 && arr[i] < arr[i + 1]) {
            i++;
        }
        if (i == 0 || i == len - 1) {
            return false;
        }
        while (i < arr.size() - 1 && arr[i] > arr[i + 1]) {
            i++;
        }
        return i == len - 1;
    }
};