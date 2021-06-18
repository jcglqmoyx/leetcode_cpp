#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int h_index = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (citations[i] >= n - i) {
                h_index = n - i;
            }
        }
        return h_index;
    }
};