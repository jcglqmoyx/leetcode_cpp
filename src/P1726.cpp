#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        if (nums.size() < 4) return 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                map[nums[i] * nums[j]]++;
            }
        }
        int count = 0;
        for (auto &x : map) {
            if (x.second >= 2) count += x.second * (x.second - 1) / 2;
        }
        return count * 8;
    }
};