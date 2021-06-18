#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector<int> res;
        res.reserve(n + 1);
        int low = 0, high = n;
        for (char c : S) {
            if (c == 'D') {
                res.push_back(high--);
            } else {
                res.push_back(low++);
            }
        }
        res.push_back(low++);
        return res;
    }
};