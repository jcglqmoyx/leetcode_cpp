#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) {
        string m = to_string(a), n = to_string(b);
        return (m + n) < (n + m);
    }

    string minNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), &cmp);
        string res;
        for (int n : nums) {
            res += to_string(n);
        }
        return res;
    }
};