#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        int max_product = 1;
        int a = -1000; // maximum number in nums
        int b = -1000; // second maximum number in nums
        int c = -1000; // third maximum number in nums
        int m = 1000; // minimum number in nums
        int n = 1000; // second minimum number in nums
        for (int num : nums) {
            if (num > c) {
                if (num > b) {
                    if (num > a) {
                        c = b;
                        b = a;
                        a = num;
                    } else {
                        c = b;
                        b = num;
                    }
                } else {
                    c = num;
                }
            }
            if (num < n) {
                if (num < m) {
                    n = m;
                    m = num;
                } else {
                    n = num;
                }
            }
        }
        return max(a * b * c, m * n * a);
    }
};