#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int> &code, int k) {
        vector<int> res(code.size());
        if (k == 0) {
            return res;
        }
        int factor = k > 0 ? 1 : -1;
        for (int i = 0; i < code.size(); i++) {
            int sum = 0;
            for (int j = 1; j <= k * factor; j++) {
                sum += code[(i + j * factor + (int) code.size()) % (int) code.size()];
            }
            res[i] = sum;
        }
        return res;
    }
};