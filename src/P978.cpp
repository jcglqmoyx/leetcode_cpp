#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        if (arr.size() == 1) return 1;
        int res = 1;
        int len = 1;
        int n = arr.size();
        bool greater = arr[0] > arr[1];
        for (int i = 0; i < n - 1; i++) {
            if (greater && arr[i] < arr[i + 1]) {
                len++;
                greater = !greater;
            } else if (!greater && arr[i] > arr[i + 1]) {
                len++;
                greater = !greater;
            } else {
                res = max(res, len);
                if (arr[i] == arr[i + 1]) len = 1;
                else len = 2;
                greater = arr[i] > arr[i + 1];
            }
            res = max(res, len);
        }
        return res;
    }
};