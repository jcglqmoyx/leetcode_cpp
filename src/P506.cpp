#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    vector<string> findRelativeRanks(vector<int> &nums) {
//        vector<string> res;
//        res.reserve(nums.size());
//        vector<int> cp(nums);
//        sort(cp.begin(), cp.end());
//        unordered_map<int, int> map;
//        for (int i = (int) cp.size() - 1; i >= 0; i--) {
//            map[cp[i]] = (int) cp.size() - i;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (map[nums[i]] == 1) {
//                res.push_back("Gold Medal");
//            } else if (map[nums[i]] == 2) {
//                res.push_back("Silver Medal");
//            } else if (map[nums[i]] == 3) {
//                res.push_back("Bronze Medal");
//            } else {
//                res.push_back(to_string(map[nums[i]]));
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        int n = nums.size();
        int *a = new int[n];
        for (int i = 0; i < n; i++) a[i] = i;
        vector<string> ans(n);
        sort(a, a + n, [&](const int x, const int y) {
            return nums[x] > nums[y];
        });
        if (n > 0) ans[a[0]] = "Gold Medal";
        if (n > 1) ans[a[1]] = "Silver Medal";
        if (n > 2) ans[a[2]] = "Bronze Medal";
        for (int i = 3; i < n; i++) ans[a[i]] = to_string(i + 1);
        return ans;
    }
};