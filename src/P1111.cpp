#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size());
        for (int i = 0; i < seq.length(); i++) {
            if (seq[i] == '(') {
                res[i] = i & 1;
            } else {
                res[i] = (i + 1) & 1;
            }
        }
        return res;
    }
};