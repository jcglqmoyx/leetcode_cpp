#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        vector<bool> res(candies.size());
        int m = 0;
        for (int candy : candies) {
            m = max(m, candy);
        }
        for (int i = 0; i < res.size(); i++) {
            res[i] = candies[i] + extraCandies >= m;
        }
        return res;
    }
};