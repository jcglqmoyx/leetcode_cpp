#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int> &encoded, int first) {
        vector<int> res;
        res.reserve(encoded.size() + 1);
        res.push_back(first);
        int prev = res.back();
        for (int i = 0; i < encoded.size(); i++) {
            res.push_back(prev ^ encoded[i]);
            prev = res.back();
        }
        return res;
    }
};