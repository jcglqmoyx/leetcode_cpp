#include <vector>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int> &A) {
        int map[10000] = {0};
        for (int n : A) {
            map[n]++;
        }
        for (int i = 0; i < 10000; i++) {
            if (map[i] == A.size() / 2) {
                return i;
            }
        }
        return 0;
    }
};