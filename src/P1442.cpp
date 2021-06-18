#include <vector>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] ^ arr[i - 1];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if ((sum[k] ^ sum[j]) == (sum[j] ^ sum[i])) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};