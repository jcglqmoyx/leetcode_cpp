#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        bitset<10001> f;
        int sum = 0;
        f[0] = 1;
        for (int num : nums) {
            f |= f << num;
            sum += num;
        }
        if (sum & 1) return false;
        return f[sum / 2];
    }
};