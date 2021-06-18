#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int> &arr) {
        int max = arr[arr.size() - 1];
        for (int i = (int) arr.size() - 1; i >= 0; i--) {
            int value = arr[i];
            arr[i] = max;
            if (value > max) {
                max = value;
            }
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};