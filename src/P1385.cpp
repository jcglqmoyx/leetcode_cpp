#include <vector>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        int res = 0;
        sort(arr2.begin(), arr2.end());
        for (int num1 : arr1) {
            bool flag = true;
            for (int num2 : arr2) {
                if (abs(num1 - num2) <= d) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res++;
            }
        }
        return res;
    }
};