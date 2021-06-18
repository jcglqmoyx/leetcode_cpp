#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int r, c;
    int k;
    unordered_map<int, int> hash;

    Solution(int n_rows, int n_cols) {
        r = n_rows, c = n_cols;
        k = r * c;
    }

    vector<int> flip() {
        int x = rand() % k;
        k--;
        int y = x;
        if (hash.count(x)) y = hash[x];
        if (hash.count(k)) {
            hash[x] = hash[k];
            hash.erase(k);
        } else {
            hash[x] = k;
        }
        return {y / c, y % c};
    }

    void reset() {
        k = r * c;
        hash.clear();
    }
};