#include <vector>

using namespace std;

class Solution {
public:
    vector<int> fenwick_tree;
    int n;

    int low_bit(int x) { return x & -x; }

    void update(int x, int dt) {
        while (x <= n) {
            fenwick_tree[x] += dt;
            x += low_bit(x);
        }
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += fenwick_tree[x];
            x -= low_bit(x);
        }
        return res;
    }

    int reversePairs(vector<int> &nums) {
        int res = 0;
        n = nums.size();
        fenwick_tree.resize(n + 1);
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for (int &num : nums) num = (int) (lower_bound(temp.begin(), temp.end(), num) - temp.begin()) + 1;
        for (int i = (int) nums.size() - 1; i >= 0; i--) {
            res += query(nums[i] - 1);
            update(nums[i], 1);
        }
        return res;
    }
};