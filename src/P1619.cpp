#include <vector>

using namespace std;

class Solution {
public:
    double trimMean(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        double sum = 0;
        for (int i = (int) arr.size() / 20; i < arr.size() * 0.95; i++) {
            sum += arr[i];
        }
        return sum / (arr.size() * 0.9);
    }
};