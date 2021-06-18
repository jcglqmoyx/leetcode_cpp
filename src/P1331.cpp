#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        vector<int> res;
        res.reserve(arr.size());
        vector<int> cp(arr);
        sort(cp.begin(), cp.end());
        unordered_map<int, int> map;
        int rank = 1;
        for (int i = 0; i < cp.size(); i++) {
            if (!map[cp[i]]) {
                map[cp[i]] = rank++;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            res.push_back(map[arr[i]]);
        }
        return res;
    }
};