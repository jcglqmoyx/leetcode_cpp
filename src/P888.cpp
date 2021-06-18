#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        unordered_set<int> set;
        for (int candy : B) {
            set.insert(candy);
        }
        int sum_a = get_sum(A), sum_b = get_sum(B);
        int diff = (sum_a - sum_b) / 2;
        for (int candy : A) {
            if (set.count(candy - diff)) {
                return {candy, candy - diff};
            }
        }
        return {};
    }

    int get_sum(const vector<int> &arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        return sum;
    }
};