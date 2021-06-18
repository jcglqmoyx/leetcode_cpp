#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int> &candies) {
        unordered_set<int> set;
        for (int candy : candies) {
            set.insert(candy);
        }
        return min(candies.size() / 2, set.size());
    }
};